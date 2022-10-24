#pragma once
#include "command.h"

class Substaction : public Command {
public:
	Substaction() : Command("-", CommandType::binary, Priority::low) {}

	double execute(const std::vector<double>& num) override {
		if (num.size() != 2)
			throw std::exception("Invalid input: Substaction must have two operands");

		return num.at(0) - num.at(1);
	}

	~Substaction() = default;
};