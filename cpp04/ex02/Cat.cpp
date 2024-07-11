#include "Cat.hpp"

Cat::Cat(void)
{
	setType("Cat");
	brain = new Brain;
	if (DEBUG)
		std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : AAnimal()
{
	if (DEBUG)
		std::cout << "Cat copy constructor called" << std::endl;
	if (this != &copy)
	{
		setType(copy.getType());
		brain = new Brain;
	}
}

Cat &Cat::operator=(const Cat &copy)
{
	if (DEBUG)
		std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		setType(copy.getType());
		*brain = *(copy.brain);
	}
	return *this;
}

Cat::~Cat(void)
{
	if (DEBUG)
		std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

Brain*	Cat::getBrain() const
{
	return (brain);
}

void	Cat::makeSound(void) const
{
	std::cout << "meow meow" << std::endl;
}
