import json
import re

# Settings
findSigs = True 		# This will find BaseNetworkable, TOD_Sky, ConVar_Graphics, etc
onlyGrabReadable = False	# This will only grab readable fields (wont grab %512958fas8h189fs)
useLooking = True		# This will use the list you make below
looking = {
    'BasePlayer',
    'BaseCombatEntity',
    'BaseEntity',
    'PlayerWalkMovement',
    'BaseMovement',
    'BaseMountable',
    'ItemDefinition',
    'PlayerEyes',
    'PlayerInput',
    'BaseProjectile',
    'RecoilProperties',
    'PlayerInput',
}

# Functions
def parse(content, limit=1900000):
    data, newdata, count = "", "", 0
    next_class, fields, current_class = False, False, ""
    sigs, pClass, varLooking, done = {}, "", "", False
    for line in content:
        line = line.strip()
        count += 1

        # Check line limit
        if count >= limit: break

        # Check main functions
        if findSigs:
            if "public static class BaseNetworkable" in line: sigs["BaseNetworkable"] = line.split("class ")[1].split(" ")[0]
            if "public static class PlayerEyes" in line: sigs["PlayerEyes"] = line.split("class ")[1].split(" ")[0]
            if "public static class TOD_Sky" in line: sigs["TOD_Sky"] = line.split("class ")[1].split(" ")[0]
            
            if "private sealed class" in line: pClass = line
            if "internal Resolution <CacheResolutions>" in line: varLooking = pClass.split("class ")[1].split(".")[0]
            if varLooking and varLooking in line and not done:
                sigs["ConVar_Graphics"] = line.split("class ")[1].split(" //")[0]
                done = True

        # Check for namespace declaration
        if line.startswith("// Namespace:"):
            next_class = True
            continue

        # Check for class declaration
        if next_class and "class " in line:
            found = False
            if useLooking:
                for item in looking:
                    if item == parseClass(line): 
                        found = True
                        break
            if useLooking and not found: continue

            current_class = parseClass(line)
            fields = True
            next_class = False
            newdata = f"namespace o{current_class.replace('%', '_')} " + "{"
            continue

        # Field Parsing
        if fields:
            # Checks
            if line.startswith(("{", "// Fields")): continue
            if onlyGrabReadable and "%" in line: continue
            if "<>" in line: continue

            # Stop if non-field line is found
            if not line.startswith(('public', 'private', 'protected', 'internal')) and not ";" in line:
                fields = False
                newdata += "\n}\n"
                if (newdata.count("=") > 1): data += newdata
                newdata = ""
                continue

            # Extract field info
            newdata += f"\n\t{parseField(line, current_class)}"
    return data, sigs
def parseScriptJSON(content, sigs):
    mainData, pLine = "namespace oMain {", ""
    for line in content:
        if mainData.count("0x") == 5: break
        if f"{sigs["BaseNetworkable"]}_TypeInfo" in line: mainData += f"\n\tinline uint64_t oBaseNetworkable = {hex(int(pLine.split(": ")[1].split(",")[0]))}; // {sigs["BaseNetworkable"]}"
        if f"{sigs["PlayerEyes"]}_TypeInfo" in line: mainData += f"\n\tinline uint64_t oPlayerEyes = {hex(int(pLine.split(": ")[1].split(",")[0]))}; // {sigs["PlayerEyes"]}"
        if f"{sigs["TOD_Sky"]}_TypeInfo" in line: mainData += f"\n\tinline uint64_t oTODSky = {hex(int(pLine.split(": ")[1].split(",")[0]))}; // {sigs["TOD_Sky"]}"
        if f"{sigs["ConVar_Graphics"]}_TypeInfo" in line: mainData += f"\n\tinline uint64_t oGraphics = {hex(int(pLine.split(": ")[1].split(",")[0]))}; // {sigs["ConVar_Graphics"]}"
        if f"MainCamera_TypeInfo" in line: mainData += f"\n\tinline uint64_t oMainCamera = {hex(int(pLine.split(": ")[1].split(",")[0]))};"
        pLine = line
    return mainData

def parseClass(line):
    return line.split("class ")[1].split(" ")[0]
def parseField(line, className):
    parts = line.split(" ")
    newName = parts[2].split(";")[0].replace("%", "_")
    return f"inline uint64_t o{newName[0].upper() + newName[1:]} = {parts[4]}; // {parts[1]}"
    #return f"inline uint64_t o{newName[0].upper() + newName[1:]} = {parts[4]}; // {className}->{parts[1]}"

newData, mainData, sigs = "", "", {}
with open('dump.cs', 'r') as f: newData, sigs = parse(f)
if findSigs:
    with open('script.json', 'r') as f: mainData = parseScriptJSON(f, sigs)
with open('output.h', 'w') as f: 
    if findSigs: f.write(f"{mainData}\n" + "}\n" + newData)
    else: f.write(newData)