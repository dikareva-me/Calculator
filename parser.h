#pragma once
#include <iostream>
#include <stack>
#include <cctype>
#include "alloper.h"

class Parser {
public:
	Parser(std::string expression) : expr(expression) {}

	void parse(std::string& token, int& inout_iter);

	bool isOperation(const std::string& token);
	bool isPrefix(const std::string& token);
	bool isPostfix(const std::string& token);
	bool isBinary(const std::string& token);
	bool isLiteral(const std::string& str);

	bool cmpPriority(const std::string& oper1, const std::string& oper2);
	void closeBrackets();
	void proccessBinaryOps(const std::string& token);

	void toRPN();


	std::vector<std::string> RPN;
	std::stack<std::string> token_stack;
	std::string expr;
};