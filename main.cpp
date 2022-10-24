#include <iostream>
#include "calc.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main() {
	const std::string plugPath = ("../plugins");
	Calculator calc;

	calc.run(plugPath);
	std::string line;
	//calc.run(plugPath);
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
	//getchar();
	return 0;
}