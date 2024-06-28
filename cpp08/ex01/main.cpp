#include "Span.hpp"

#define ALOT_NUMBER_TEST

int main()
{
#ifdef ALOT_NUMBER_TEST
	Span sp = Span(10000);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try {
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
#else
	std::cout << "===== 10.0000 numbers test ====" << std::endl;
	Span sp = Span(10000);
	sp.addAlotRandomNumbers();
	try {
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
#endif
	return 0;
}