#pragma once
#include "parser.h"
#include <string>

class Calculator {
public:
	//Parser parser{ expr };
	//Operations possible_opers;


	void run(const std::string& path);
	double calculate(Parser& parser);
	std::string expr;
};
