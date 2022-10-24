#include "alloper.h"

#include <filesystem>
#include <exception>
#include <functional>

//Operations::KeyMap Operations::km = { {1, 'a'}, {2, 'b'} };


command_ptr mult = std::make_shared<Multiplication>();
command_ptr division = std::make_shared <Division>();
command_ptr minus = std::make_shared <Substaction>();
command_ptr plus = std::make_shared <Addition>();
command_ptr unary_minus = std::make_shared <Unary_minus>();


oper_map_t Operations::operations = {
	{mult->to_string(), mult},
	{division->to_string(), division},
	{plus->to_string(), plus},
	{minus->to_string(), minus},
	{unary_minus->to_string(), unary_minus}
};


void Operations::loadDLL(const std::string& path) {
	/*
	if (!std::filesystem::exists(path))
		throw std::exception("Error: No files in file input");

	for (auto plug : std::filesystem::directory_iterator(path)) {
		HMODULE dll = LoadLibrary((plug.path().c_str()));
		if (!dll)
			throw std::exception("Error: Files in directory is not dll format");

		auto loader = (dll_operations)GetProcAddress(dll, "LoadOperation");
		if (!loader)
			throw std::exception("Error: Invalid dll library");
		Command* op = loader();
		operations[op->to_string()] = std::make_shared<Command>(op);

		libs.emplace_back(dll);
		/*dll_operations* func = (dll_operations*)GetProcAddress(dll, "GetOperations");
		if (func == static_cast<dll_operations*>(NULL)) {
			FreeLibrary(dll);
			throw std::exception("Error: Invalid dll library");
			continue;
		}

		auto opers = func();
		if (!opers) {
			FreeLibrary(dll);
			continue;
		}
		std::for_each(opers->begin(), opers->end(),
			[this](Command& op) {
				operations.emplace(op.to_string(), std::make_shared<Command>(op));
			});
	//	delete opers;
		libs.emplace_back(dll);
	}*/
}
