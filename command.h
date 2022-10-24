#pragma once
#include <iostream>
#include <vector>

class Calculator;

class Command {
public:
	enum class CommandType {
		binary,
		postfix,
		prefix
	};

	enum class Priority {
		low,
		medium,
		high
	};


	Command(std::string _val, CommandType _type = CommandType::binary,
		Priority _prior = Priority::low) : val(_val), type(_type), prior(_prior) {};

	virtual double execute(const std::vector<double>&) = 0;
//	virtual double undo() = 0;

	Priority getPriority() {
		return prior;
	}

	CommandType getType() {
		return type;
	}

	std::string to_string() {
		return val;
	}
	virtual ~Command() = default;

protected:
	CommandType type;
	Priority prior;
	std::string val;
};


