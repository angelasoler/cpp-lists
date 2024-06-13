
#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	if (DEBUG)
		std::cout << "AAnimal constructor called" << std::endl;
}

void	AAnimal::setType(std::string type)
{
	this->type = type;
}

std::string	AAnimal::getType() const
{
	return (this->type);
}

AAnimal::AAnimal(const AAnimal &copy)
{
	if (DEBUG)
		std::cout << "AAnimal copy constructor called" << std::endl;
	*this = copy;
}

AAnimal &AAnimal::operator=(const AAnimal &copy)
{
	if (DEBUG)
		std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->setType(copy.getType());
	}
	return *this;
}

AAnimal::~AAnimal(void)
{
	if (DEBUG)
		std::cout << "AAnimal destructor called" << std::endl;
}

void	AAnimal::makeSound(void) const
{
	std::cout << "I'm just an AAnimal" << std::endl;
}
