#pragma once
#include "command.h"

class Division : public Command {
public:
	Division() : Command("/", CommandType::binary, Priority::medium){}

	double execute(const std::vector<double>& num) override {
		if (num.size() != 2)
			throw std::exception("Invalid input: Division must have two operands.");

		return num.at(0) / num.at(1);
	}

	~Division() = default;
};