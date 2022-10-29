#pragma once
#include "command.h"

class Addition : public Command {
public:
	Addition() : Command("+", CommandType::binary, Priority::low) {}

	double execute(const std::vector<double>& num) override {
		if (num.size() != 2)
			throw std::exception("Invalid input: Addition must have two operands");

		return num.at(0) + num.at(1);
	}

	~Addition() = default;
};