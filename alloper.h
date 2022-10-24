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
//using dll_operations = std::list<Command> *();
using oper_map_t = std::map<std::string, command_ptr>;
typedef Command* (*dll_operations)();

class Operations {
public:


	//typedef std::map<int, char> KeyMap;
	//static KeyMap km;

	//void initOpers();
	void loadDLL(const std::string& path);

	~Operations() {
		for (auto& dll : libs)
			FreeLibrary(dll);
		operations.clear();
	}

	//std::vector <Command> opers;
	std::vector<HMODULE> libs;
	static oper_map_t operations;
};

