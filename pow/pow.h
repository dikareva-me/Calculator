#pragma once
#include "../command.h"
#include "../alloper.h"

class Pow : public Command {
public:
	Pow() : Command("^", CommandType::binary, Priority::high) {}

	double execute(const std::vector<double>& num) override {
		if (num.size() != 2)
			throw std::exception("Invalid input: Exponentiation must have two operands");

		return pow(num.at(0), num.at(1));
	}

	~Pow() = default;
};
