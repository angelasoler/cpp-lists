
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
		*n = top * *n;
		break;
	case '+':
		*n = top + *n;
		break;
	case '-':
		*n = top - *n;
		break;
	case '/':
		*n = top / *n;
		break;
	default:
		break;
	}
}

void	RPN::makeOperation(std::stack<char> &expression)
{
	char	sign;
	int		n;
	int		digit;

	while (!expression.empty()) {
		if (expression.top() != '*' && 
			expression.top() != '/' &&
			expression.top() != '+' &&
			expression.top() != '-')
		{
			std::stringstream ss;
			ss << expression.top();
			ss >> digit;
			operations.push(digit);
		}
		else {
			sign = expression.top();
			n = operations.top();
			operations.pop();
			makeOp(&n, sign, operations.top());
			operations.pop();
			operations.push(n);
		}
		expression.pop();
	}
	std::cout << n << std::endl;
}
