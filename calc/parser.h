#pragma once
#include <iostream>
#include <stack>
#include <cctype>
#include "alloper.h"

class Parser {
public:
	Parser(string expression):expr(expression) {}

	void toRPN();
	bool isLiteral(const string& str);

	std::vector<string> RPN;

private:
	bool isOperation(const string& token);
	bool isPrefix(const string& token);
	bool isPostfix(const string& token);
	bool isBinary(const string& token);
	void parse(string& token, int& inout_iter);

	bool cmpPriority(const string& oper1, const string& oper2);
	void closeBrackets();
	void proccessBinaryOps(const string& token);

	std::stack<string> token_stack;
	string expr;
};