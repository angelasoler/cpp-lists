#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	RPN					Rpn;
	std::stack<char>	expressions;


	if (argc != 2) {
		std::cerr << "Error: Bad argument." << std::endl;
		return (1);
	}
	for (const char* p = argv[1]; *p != '\0'; ++p) {
		expressions.push(*p);
	}
	Rpn.makeOperation(expressions);
}
