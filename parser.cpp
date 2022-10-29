#include "parser.h"

void Parser::parse(string& token, int& inout_iter) {
	if (isdigit(expr[inout_iter])) {
		while (isdigit(expr[inout_iter]) || expr[inout_iter] == '.' && inout_iter < expr.size()) {
			token.insert(token.end(), expr[inout_iter]);
			inout_iter++;
		}
	}
	else if (expr[inout_iter] == ')' || expr[inout_iter] == '(') {
		token.insert(token.end(), expr[inout_iter]);
		inout_iter++;
	}
	else {
		for (auto& str_oper : Operations::operations) {
			string tmp = expr.substr(inout_iter, str_oper.first.size());
			if (tmp.compare(str_oper.first) == 0) {
				inout_iter += tmp.size();
				token = tmp;
				return;
			}
		}
		token = expr[inout_iter];
	}
}


bool Parser::isOperation(const string& token) {
	return Operations::operations.find(token) != Operations::operations.end();
}

bool Parser::isPrefix(const string& token) {
	auto oper = Operations::operations.find(token);
	if (oper == Operations::operations.end())
		return false;
	return oper->second->getType() == Command::CommandType::prefix;
}

bool Parser::isPostfix(const string& token) {
	auto oper = Operations::operations.find(token);
	if (oper == Operations::operations.end())
		return false;
	return oper->second->getType() == Command::CommandType::postfix;
}

bool Parser::isBinary(const string& token) {
	auto oper = Operations::operations.find(token);
	if (oper == Operations::operations.end())
		return false;
	return oper->second->getType() == Command::CommandType::binary;
}

bool Parser::isLiteral(const string& str) {
	if (str.empty() || str == "-")
		return false;

	for (char s : str)
		if (!isdigit(s) && s != '.' && s != '-')
			return false;

	return true;
}


bool Parser::cmpPriority(const string& oper1, const string& oper2) {
	auto tmp1 = Operations::operations.find(oper1);
	auto tmp2 = Operations::operations.find(oper2);

	return tmp1->second->getPriority() >= tmp2->second->getPriority();
}

void Parser::closeBrackets() {
	if (!token_stack.empty())
		while (token_stack.top() != "(") {
			RPN.emplace_back(token_stack.top());
			token_stack.pop();
		}
	token_stack.pop();
}

void Parser::proccessBinaryOps(const string& token) {
	while (!token_stack.empty() && isOperation(token_stack.top()) && 
		(isPrefix(token_stack.top()) || cmpPriority(token_stack.top(), token))) {
		RPN.push_back(token_stack.top());
		token_stack.pop();
	}
	token_stack.push(token);
}

void Parser::toRPN() {
	for (int i = 0; i < expr.size();) {


		if (std::isspace(expr[i])) {
			i++;
			continue;
		}
		string token;
		parse(token, i);
		if (isLiteral(token) || isPostfix(token))
			RPN.emplace_back(token);

		else if (isPrefix(token) || token == "(")
			token_stack.push(token);

		else if (token == ")")
			closeBrackets();

		else if (isBinary(token))
			proccessBinaryOps(token);

		else throw std::exception("Error: Invalid expression input");

	}

	while (!token_stack.empty()) {
		RPN.emplace_back(token_stack.top());
		token_stack.pop();
	}
}