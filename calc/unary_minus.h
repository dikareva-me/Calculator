#pragma once
#include "command.h"

class Unary_minus : public Command {
public:
	Unary_minus() : Command("~", CommandType::prefix, Priority::low) {}

	double execute(const std::vector<double>& num) override {
		if (num.size() != 1)
			throw std::exception("Invalid input: Unary minus must have one operand");

		return -num.at(0);
	}

	~Unary_minus() = default;
};