
#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
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

		void	makeOperation(std::stack<char> expression);
};

#endif /* RPN_HPP */
