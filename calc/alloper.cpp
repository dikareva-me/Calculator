#include "alloper.h"

#include <filesystem>
#include <exception>
#include <functional>


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


void Operations::loadDLL(const string& path) {
	if (!std::filesystem::exists(path))
		throw std::exception("Error: No files in file input");

	for (auto plug : std::filesystem::directory_iterator(path)) {
		HMODULE dll = LoadLibrary((plug.path().c_str()));
		if (!dll)
			throw std::exception("Error: Files in directory is not dll format");

		dll_operations loader = (dll_operations)GetProcAddress(dll, "LoadOperation");
		auto err = GetLastError();
		if (!loader)
			throw std::exception("Error: Invalid dll library");

		Wrapper_dllfunc* wrp = loader();
		operations[wrp->func_class->to_string()] = command_ptr(wrp->func_class);

		libs.emplace_back(dll);
	}
}
