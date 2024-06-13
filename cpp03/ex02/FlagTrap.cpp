
#include "FlagTrap.hpp"

FlagTrap::FlagTrap(void)
{
	if (DEBUG)
		std::cout << "FlagTrap constructor called" << std::endl;
}

FlagTrap::FlagTrap(std::string name)
{
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	if (DEBUG)
		std::cout << "FlagTrap constructor called" << std::endl;
}

FlagTrap::~FlagTrap(void)
{
	if (DEBUG)
		std::cout << "FlagTrap destructor called" << std::endl;
}

void	FlagTrap::highFivesGuys(void)
{
	std::cout << "Hey there! High five guys!" << std::endl;
}
