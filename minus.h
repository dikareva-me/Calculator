#pragma once
#include "command.h"

class Substraction : public Command {
public:
	Substraction() : Command("-", CommandType::binary, Priority::low) {}

	double execute(const std::vector<double>& num) override {
		if (num.size() != 2)
			throw std::exception("Invalid input: Substraction must have two operands");

		return num.at(0) - num.at(1);
	}

	~Substraction() = default;
};