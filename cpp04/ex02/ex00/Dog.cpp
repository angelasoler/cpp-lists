
#include "Dog.hpp"

Dog::Dog(void)
{
	setType("Dog");
	if (DEBUG)
		std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal()

{
	if (DEBUG)
		std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog &Dog::operator=(const Dog &copy)
{
	if (DEBUG)
		std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		setType(copy.getType());
	}
	return *this;
}

Dog::~Dog(void)
{
	if (DEBUG)
		std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "woof woof" << std::endl;
}
