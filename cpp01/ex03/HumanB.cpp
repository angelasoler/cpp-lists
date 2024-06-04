
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	if (DEBUG)
		std::cout << "HumanB constructor called" << std::endl;
}

HumanB::~HumanB(void)
{
	if (DEBUG)
		std::cout << "HumanB destructor called" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack()
{
	if (this->weapon) {
		std::cout << this->name
			<< " attacks with their "
			<< this->weapon->getType() << std::endl;
	}
	else {
		std::cout << this->name
			<< " cannot attack, he has no weapon!"
			<< std::endl;
	}
}
