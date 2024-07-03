#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	RPN					Rpn;
	std::stack<char>	expressions;
	std::string			input(argv[1]);


	if (argc != 2) {
		std::cerr << "Error: Bad argument." << std::endl;
		return (1);
	}
	for (std::string::reverse_iterator it = input.rbegin(); it != input.rend(); ++it) {
		if (*it == ' ')
			continue ;
		expressions.push(*it);
	}
	Rpn.makeOperation(expressions);
}
