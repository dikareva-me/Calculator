#pragma once
#include "../command.h"
#include "../alloper.h"
#include <cmath>

class Sin : public Command {
public:
	Sin() : Command("sin", CommandType::prefix, Priority::high) {}

	double execute(const std::vector<double>& num) override {
		if (num.size() != 1)
			throw std::exception("Invalid input: Sin must have one operand");

		return sin(num.at(0));
	}

	~Sin() = default;
};