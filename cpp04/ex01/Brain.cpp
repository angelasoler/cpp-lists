
#include "Brain.hpp"

Brain::Brain(void)
{
	if (DEBUG)
		std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	if (DEBUG)
		std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

Brain &Brain::operator=(const Brain &copy)
{
	if (DEBUG)
		std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < N_IDEAS; i++)
			ideas[i] = copy.ideas[i];
	}
	return *this;
}

Brain::~Brain(void)
{
	if (DEBUG)
		std::cout << "Brain destructor called" << std::endl;
}
