
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	if (DEBUG)
		std::cout << "HumanA constructor called" << std::endl;
}

HumanA::~HumanA(void)
{
	if (DEBUG)
		std::cout << "HumanA destructor called" << std::endl;
}

void	HumanA::attack()
{
	std::cout << this->name
			<< " attacks with their "
			<< this->weapon.getType() << std::endl;
}
