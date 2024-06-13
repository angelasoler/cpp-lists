
#include "Cat.hpp"

Cat::Cat(void)
{
	setType("Cat");
	if (DEBUG)
		std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal()

{
	if (DEBUG)
		std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat &Cat::operator=(const Cat &copy)
{
	if (DEBUG)
		std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		setType(copy.getType());
	}
	return *this;
}

Cat::~Cat(void)
{
	if (DEBUG)
		std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "meow meow" << std::endl;
}
