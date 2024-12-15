#pragma once
#include <iostream>

class c_memory {
public:
	DWORD pid;
	uint64_t module;
	HANDLE handle;
public:
	bool valid(uint64_t ptr) {
		if (ptr < 0xFFFFFF || ptr > 0x7FFFFFFF0000)
			return false;
		if (!ptr || !sizeof(ptr) || ptr == 0)
			return false;

		return true;
	}

	// read
	template <typename t>
	t read(uint64_t ptr) {
		if (!valid(ptr)) return t();
		t buffer{};
		ReadProcessMemory(handle, (LPVOID)ptr, &buffer, sizeof(buffer), 0);
		return buffer;
	}
	uint64_t read_chain(uint64_t ptr, std::vector<uint64_t> offsets) {
		uint64_t addr = ptr;
		for (auto i = 0; i < offsets.size(); ++i) {
			if (!valid(addr)) return 0;
			ReadProcessMemory(handle, (LPVOID)addr, &addr, sizeof(addr), 0);
			addr += offsets[i];
		}
		return read<uint64_t>(addr);
	}
	std::string read_str(uint64_t ptr) {
		char buffer[128];
		ReadProcessMemory(handle, (LPVOID)ptr, &buffer, sizeof(buffer), 0);
		return std::string(buffer);
	}
	std::wstring read_wstr(uint64_t ptr) {
		wchar_t buffer[1024 * sizeof(wchar_t)];
		ReadProcessMemory(handle, (LPVOID)ptr, &buffer, sizeof(buffer), 0);
		return std::wstring(buffer);
	}

	// write
	template <typename t>
	bool write(uint64_t ptr, t val) {
		return !valid(ptr) ? false : WriteProcessMemory(handle, (LPVOID)ptr, &val, sizeof(val), 0);
	}

	// decrypt
	bool TEST_BITD(uint64_t val, uint64_t pos) {
		return (val & (1 << pos)) != 0;
	}
	uintptr_t decrypt_il2cppHandle(uint32_t ptr) {
		// IDA -> Strings -> "il2cpp_gchandle_get_target" -> F5 -> il2cpp_gchandle_get_target_0
		uint64_t rdi_1 = ptr >> 3;
		uint64_t rcx_1 = (ptr & 7) - 1;
		uint64_t baseAddr = module + 0xD6B2830 + 0x28 * rcx_1;
		uint32_t limit = read<uint32_t>(baseAddr + 0x10);
		if (rdi_1 < limit) {
			uint64_t objAddr = read<uint64_t>(baseAddr);
			uint64_t bitMask = read<uint64_t>(objAddr + ((rdi_1 >> 5) << 2));
			if (TEST_BITD(bitMask, rdi_1 & 0x1f)) {
				uint64_t ObjectArray = read<uint64_t>(baseAddr + 0x8) + (rdi_1 << 3);
				return read<BYTE>(baseAddr + 0x14) > 1
					? read<uint64_t>(ObjectArray)
					: ~read<uint64_t>(ObjectArray);
			}
		}
		return 0;
	}
	uint64_t decrypt_network(uint64_t ptr) {
		// IDA -> 18[addr] ->  F5 -> function that uses baseNetworkable -> result / where result should be

		uintptr_t* v5;
		int v6;
		int v7;
		uintptr_t v23;

		v5 = &v23;
		v6 = 2;
		v23 = read<uintptr_t>(ptr + 0x18);
		do {
			v7 = *(DWORD*)v5;
			v5 = (uintptr_t*)((char*)v5 + 4);
			*((DWORD*)v5 - 1) = (((v7 ^ 0x9F7C3F95) << 22) | ((v7 ^ 0x9F7C3F95) >> 10)) - 1788320959;
			--v6;
		} while (v6);
		signed __int64 v8 = *reinterpret_cast<signed __int64*>(&v23);
		return decrypt_il2cppHandle(v8);
	}
	uint64_t decrypt_ulong(uint64_t ptr) {
		// IDA -> 18[playerEyesAddr] -> F5 -> function that uses a2 -> return function -> result / where result should be

		__m128* v4; // rdx
		int v5; // r8d
		int v6; // eax
		__m128 v22; // [rsp+20h] [rbp-28h] BYREF

		v4 = &v22;
		v5 = 2;
		memcpy(&v22, &ptr, sizeof(ptr));
		do {
			v6 = *(DWORD*)v4;
			v4 = (__m128*)((char*)v4 + 4);
			*((DWORD*)v4 - 1) = (((2 * (v6 + 557430006)) | ((unsigned int)(v6 + 557430006) >> 31)) + 2100434178) ^ 0x64BD88F;
			--v5;
		} while (v5);
		signed __int64 v7 = *reinterpret_cast<signed __int64*>(&v22);
		return (v7);
	}
	uint64_t decrypt_inventory(uint64_t ptr) {
		return decrypt_il2cppHandle((uint64_t)decrypt_ulong(read<uint64_t>(ptr + 0x18)));
	}
} memory;