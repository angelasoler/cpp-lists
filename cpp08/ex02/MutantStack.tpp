
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>

class MutantStack
{
	private:
	public:
		MutantStack(void);
		MutantStack(const MutantStack &copy);
		MutantStack &operator=(const MutantStack &copy);
		~MutantStack(void);
};

#include "MutantStack.tpp"

#endif /* MUTANTSTACK_HPP */
