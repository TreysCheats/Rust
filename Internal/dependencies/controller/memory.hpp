#pragma once
#include <vector>
#include <iostream>

inline class c_memory {
public:
	uint64_t module;
public:
	bool query(uint64_t ptr) {
		MEMORY_BASIC_INFORMATION mbi;
		if (VirtualQuery((void*)ptr, &mbi, sizeof(mbi))) {
			DWORD mask = (PAGE_GUARD | PAGE_NOACCESS | PAGE_EXECUTE | PAGE_EXECUTE_READ);
			bool accessible = !(mbi.Protect & mask);
			return (accessible && (mbi.State == MEM_COMMIT));
		}
		return false;
	}
	bool valid(uint64_t ptr) {
		if (!ptr || !sizeof(ptr))
			return false;
		if (ptr < 0xFFFFFF || ptr > 0x7FFFFFFF0000)
			return false;
		//if (!query(ptr))
			//return false;

		return true;
	}

	// read
	template <typename t>
	t read(uint64_t ptr) {
		if (!valid(ptr)) return t();
		return *(t*)(ptr);
	}
	uint64_t read_chain(uint64_t ptr, std::vector<uint64_t> offsets) {
		uint64_t addr = ptr;
		for (auto i = 0; i < offsets.size(); ++i) {
			addr = read<uint64_t>(addr);
			addr += offsets[i];
		}
		return read<uint64_t>(addr);
	}
	template <typename t>
	t read_chain(uint64_t ptr, std::vector<uint64_t> offsets) {
		uint64_t addr = ptr;
		for (auto i = 0; i < offsets.size() - 1; i++) {
			addr = read<uint64_t>(addr + offsets[i]);
		}
		return read<t>(addr + offsets[offsets.size() - 1]);
	}

	std::string read_str(uint64_t ptr) {
		try {
			if (!valid(ptr)) return "";
			return (std::string)(char*)(ptr);
		}
		catch (std::exception& e) {

		}
		return "";
	}
	std::wstring read_wstr(uint64_t ptr) {
		try {
			if (!valid(ptr)) return L"";
			return (std::wstring)(wchar_t*)(ptr);
		}
		catch (std::exception& e) {

		}
		return L"";
	}

	// write
	template <typename t>
	void write(uint64_t ptr, t val) {
		if (!valid(ptr)) return;
		*(t*)(ptr) = val;
	}
} memory;