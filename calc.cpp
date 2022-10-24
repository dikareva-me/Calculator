#include "calc.h"


double Calculator::calculate(Parser& parser)  {
	auto RPN = parser.RPN;
	while (RPN.size() != 1) {
		unsigned i;
		for (i = 0; i < RPN.size(); ++i)
			if (!parser.isLiteral(RPN[i]))
				break;

		auto op = Operations::operations.at(RPN[i]);
		if (op->getType() == Command::CommandType::binary) {
			double res = op->execute({ std::stod(RPN[i - 2]), std::stod(RPN[i - 1]) });
			RPN[i - 2] = std::to_string(res);
			RPN.erase(RPN.begin() + i - 1);
			RPN.erase(RPN.begin() + i - 1);
		}
		else {
			double res = op->execute({ std::stod(RPN[i - 1]) });
			RPN[i - 1] = std::to_string(res);
			RPN.erase(RPN.begin() + i);
		}
	}

	double result = std::stod(RPN.front());
	return result;
}

void Calculator::run(const std::string& path) {
	Operations oper;
//	std::string line;

	std::cout << "Print your expression:" << std::endl;
	while (std::getline(std::cin, expr)) {
		if (!expr.size())
			break;

		/*try {
			oper.loadDLL(path);
		}
		catch (std::exception ex) {
			std::cout << ex.what() << std::endl;
		}*/

		Parser parser{ expr };
		try {
			parser.toRPN();
		}
		catch (std::exception ex) {
			std::cout << ex.what() << std::endl;
			return;
		}

		double res;
		try {
			res = calculate(parser);
		}
		catch (std::exception ex) {
			std::cout << ex.what() << std::endl;
			return;
		}
		std::cout << "Answer: " << res << std::endl;

		std::cout << "Print your expression:" << std::endl;
	}
}