#include "MutantStack.hpp"

MutantStack::MutantStack(void) {}

MutantStack::MutantStack(const MutantStack &copy)
{
	*this = copy;
}

MutantStack &MutantStack::operator=(const MutantStack &copy)
{
	if (this != &copy)
	{
	}
	return *this;
}

MutantStack::~MutantStack(void) {}
