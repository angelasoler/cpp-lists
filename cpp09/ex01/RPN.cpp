
#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
	if (this != &copy)
	{
	}
	return *this;
}

RPN::~RPN(void) {}

void	makeOp(int *n, char sign, int top)
{
	switch (sign)
	{
	case '*':
		*n *= top;
		break;
	case '+':
		*n += top;
		break;
	case '-':
		*n -= top;
		break;
	case '/':
		*n /= top;
		break;
	default:
		break;
	}
}

void	RPN::makeOperation(std::stack<char> expression)
{
	char	sign;
	int		n;

	while (!expression.empty()) {
		if (expression.top() != '*' && 
			expression.top() != '/' &&
			expression.top() != '+' &&
			expression.top() != '-')
			operations.push(std::atoi(&expression.top()));
		else {
			sign = expression.top();
			n = operations.top();
			operations.pop();
			makeOp(&n, sign, operations.top());
		}
		expression.pop();
	}
}
