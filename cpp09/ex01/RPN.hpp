
#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <cstdlib>

class RPN
{
	private:
		std::stack<int>		operations;
	public:
		RPN(void);
		RPN(const RPN &copy);
		RPN &operator=(const RPN &copy);
		~RPN(void);

		void	readExpression(std::stack<char> &expression);
		int		makeOperation(char sign);
};

#endif /* RPN_HPP */
