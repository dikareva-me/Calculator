#pragma once
#include "parser.h"
#include <string>

class Calculator {
public:
	void run(const string& path);
	double calculate(Parser& parser);
	string expr;
};
