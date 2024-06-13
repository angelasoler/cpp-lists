
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	if (DEBUG)
		std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	if (DEBUG)
		std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	if (DEBUG)
		std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (!EnergyPoints)
	{
		std::cout << name << " has no energy points" << std::endl;
		return ;
	}
	std::cout << "ScavTrap "
				<< name
				<< " attacks "
				<< target
				<< " causing "
				<< AttackDamage
				<< " point of damage! "
				<< std::endl;
	setEnergyPoints(getEnergyPoints() - 1);
}
