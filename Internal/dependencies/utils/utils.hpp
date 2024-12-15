#pragma once
#include "../../common.hpp"
#include <sstream>

#define red			"\033[31m"
#define green		"\033[32m"
#define yellow		"\033[33m"
#define dark_blue	"\033[34m"
#define purple		"\033[35m"
#define light_blue	"\033[36m"
#define white		"\033[37m"

inline class c_utils {
public:
	void print(const std::string text) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD written;
		WriteConsoleA(hConsole, text.c_str(), (DWORD)text.size(), &written, NULL);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
	
	template <typename t>
	std::string toStr(t value) {
		return std::to_string(value);
	}
	std::string decToHex(uint64_t dec) {
		std::stringstream ss;
		ss << std::hex << dec;
		return ss.str();
	}
	uint64_t hexToDec(std::string hex) {
		uintptr_t dec;
		std::stringstream ss;
		ss << hex;
		ss >> std::hex >> dec;
		return dec;
	}
} utils;