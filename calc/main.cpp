#include <iostream>
#include "calc.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <filesystem>
#include <crtdbg.h>

int main() {
	const string plugPath = ("plugins");

	Calculator calc;

	calc.run(plugPath);

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
	return 0;
}