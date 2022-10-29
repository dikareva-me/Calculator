#pragma once
#include "../command.h"
#include "../alloper.h"
#include <cmath>

class Cos : public Command {
public:
	Cos() : Command("cos", CommandType::prefix, Priority::high) {}

	double execute(const std::vector<double>& num) override {
		if (num.size() != 1)
			throw std::exception("Invalid input: Cos must have one operand");

		return cos(num.at(0));
	}

	~Cos() = default;
};