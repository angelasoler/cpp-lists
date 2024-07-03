
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

bool	isOperator(char op)
{
	if (op == '*' || op == '/' || op == '+' || op == '-') {
		return true;
	}
	if (!isdigit(op)) {
		std::cout << "Error" << std::endl;
		exit (1);
	}
	return false;
}

int	RPN::makeOperation(char sign)
{
	int	ret;

	ret = operations.top();
	operations.pop();
	switch (sign)
	{
	case '*':
		ret = operations.top() * ret;
		break;
	case '+':
		ret = operations.top() + ret;
		break;
	case '-':
		ret = operations.top() - ret;
		break;
	case '/':
		ret = operations.top() / ret;
		break;
	default:
		break;
	}
	operations.pop();
	operations.push(ret);
	return (ret);
}

void	RPN::readExpression(std::stack<char> &expression)
{
	char	sign;
	int		ret;
	int		digit;

	while (!expression.empty()) {
		if (!isOperator(expression.top())) {
			std::stringstream	ss;
			ss << expression.top();
			ss >> digit;
			operations.push(digit);
		}
		else {
			if (operations.size() < 2) {
				std::cout << "Invalid expression" << std::endl;
				return ;
			}
			sign = expression.top();
			ret = makeOperation(sign);
		}
		expression.pop();
	}
	std::cout << ret << std::endl;
}
