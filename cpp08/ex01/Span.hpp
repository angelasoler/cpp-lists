
#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		unsigned			n;
		std::vector<int>	cont;
	public:
		Span(void);
		Span(unsigned n);
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		~Span(void);

		void	addNumber(int number);
		int		shortestSpan();
		int		longestSpan();
};

#endif /* SPAN_HPP */
