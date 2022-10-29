#pragma once
#include <iostream>
#include <vector>

using std::string;

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


	Command(string _val, CommandType _type = CommandType::binary,
		Priority _prior = Priority::low) : val(_val), type(_type), prior(_prior) {};

	virtual double execute(const std::vector<double>&) = 0;

	Priority getPriority() {
		return prior;
	}

	CommandType getType() {
		return type;
	}

	string to_string() {
		return val;
	}
	virtual ~Command() = default;

protected:
	CommandType type;
	Priority prior;
	string val;
};


