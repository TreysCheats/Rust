#pragma once
#include "../../common.hpp"
#include "baseplayer.hpp"

class c_BaseNetworkable {
public:
	uint64_t networkable = 123, staticFields, wrapperPtr, wrapper, parentStatic, parentClass, entityList;
public:
	void init() {
		initialized = true;

		networkable = memory.read<uint64_t>(memory.module + oMain::oBaseNetworkable);
		//utils.print("\033[32m[+]\033[37m networkable: \033[36m0x" + utils.decToHex(networkable) + "\n");
		staticFields = memory.read<uint64_t>(networkable + 0xB8);
		//utils.print("\033[32m[+]\033[37m staticFields: \033[36m0x" + utils.decToHex(staticFields) + "\n");
		wrapperPtr = memory.read<uint64_t>(staticFields + 0x38); // <BaseNetworkable.%3dd20a314d4a19694d9f389572e4dc2e5e4e6c57>
		//utils.print("\033[32m[+]\033[37m wrapperPtr: \033[36m0x" + utils.decToHex(wrapperPtr) + "\n");
		wrapper = memory.decrypt_network(wrapperPtr);
		//utils.print("\033[32m[+]\033[37m wrapper: \033[36m0x" + utils.decToHex(wrapper) + "\n");
		parentStatic = memory.read<uint64_t>(wrapper + 0x10);
		//utils.print("\033[32m[+]\033[37m parentStatic: \033[36m0x" + utils.decToHex(parentStatic) + "\n");
		parentClass = memory.decrypt_network(parentStatic);
		utils.print("\033[32m[+]\033[37m parentClass: \033[36m0x" + utils.decToHex(parentClass) + "\n");
		entityList = memory.read<uint64_t>(parentClass + 0x10);
		//utils.print("\033[32m[+]\033[37m entityList: \033[36m0x" + utils.decToHex(entityList) + "\n");
	}

	int getSize() {
		if (!initialized) init();
		return memory.read<int>(entityList + 0x18);
	}
	uint64_t getItems() {
		if (!initialized) init();
		return memory.read<uint64_t>(entityList + 0x10);
	}
	c_BasePlayer* getLocal() {
		return memory.read<c_BasePlayer*>(getItems() + 0x20);
	}
private:
	bool initialized;
} BaseNetworkable;