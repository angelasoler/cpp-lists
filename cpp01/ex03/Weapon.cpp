
#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
	if (DEBUG)
		std::cout << "Weapon constructor called" << std::endl;
}

Weapon::~Weapon(void)
{
	if (DEBUG)
		std::cout << "Weapon destructor called" << std::endl;
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

const std::string&	Weapon::getType()
{
	return (this->type);
}
