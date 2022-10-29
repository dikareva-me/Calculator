#pragma once
#include "command.h"
#include "div.h"
#include "mult.h"
#include "minus.h"
#include "plus.h"
#include "unary_minus.h"
#include <map>
#include <filesystem>
#include <windows.h>
#include <iostream>

using command_ptr = std::shared_ptr<Command>;
using oper_map_t = std::map<string, command_ptr>;


class Operations {
public:
	void loadDLL(const string& path);

	~Operations() {
		for (auto& dll : libs)
			FreeLibrary(dll);
		operations.clear();
	}

	static oper_map_t operations;

private:
	std::vector<HMODULE> libs;
};

class Wrapper_dllfunc {
public:
	Wrapper_dllfunc(command_ptr dll_oper) : func_class(dll_oper) {}

	command_ptr func_class;
};

using dll_operations = Wrapper_dllfunc * (*)();