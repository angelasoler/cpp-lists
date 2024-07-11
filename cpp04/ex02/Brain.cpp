
#include "Brain.hpp"

Brain::Brain(void)
{
	if (DEBUG)
		std::cout << "Brain default constructor called" << std::endl;
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

std::string	Brain::getIdea(int index)
{
	return (ideas[index]);
}

void	Brain::setIdea(int index, std::string idea)
{
	ideas[index] = idea;
}

Brain::~Brain(void)
{
	if (DEBUG)
		std::cout << "Brain default destructor called" << std::endl;
}
