#pragma once
#include "command.h"

class Multiplication : public Command {
public:
	Multiplication() : Command("*", CommandType::binary, Priority::medium) {}

	double execute(const std::vector<double>& num) override {
		if (num.size() != 2)
			throw std::exception("Invalid input: Multiplication must have two operands");

		return num.at(0) * num.at(1);
	}

	~Multiplication() = default;
};