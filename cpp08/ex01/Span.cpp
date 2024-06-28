
#include "Span.hpp"

Span::Span(void) {}

Span::Span(unsigned int n) : n(n) {}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span &Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
	}
	return *this;
}

Span::~Span(void) {}

void	Span::addNumber(int number)
{
	if (cont.size() < n)
		cont.resize(cont.size() + 1, number);
	else
		throw(std::runtime_error("You hace 0 spaces left!"));
}

void	Span::addAlotRandomNumbers()
{
	srand(time(0));

	while (cont.size() < n)
		addNumber(rand() % 220000000);
}

int	Span::shortestSpan()
{
	std::vector<int>			tmp;
	std::vector<int>::iterator	i;

	if (cont.size() <= 1)
		throw(std::runtime_error("There is too few itens om vector!"));
	tmp = cont;
	i = tmp.begin();
	std::sort(tmp.begin(), tmp.end());
	int	ret = *(i + 1) - *i;
		while (tmp.end() != (i + 1)) {
			int	diff = *(i + 1) - *i;
			if (ret > diff)
				ret = diff;
			i++;
		}
	return	ret;
}

int	Span::longestSpan()
{
	std::vector<int>	tmp;

	if (cont.size() <= 1)
		throw(std::runtime_error("There is too few itens on vector!"));
	tmp = cont;
	std::sort(tmp.begin(), tmp.end());
	return (tmp.at(tmp.size() - 1) - tmp.at(0));
}
