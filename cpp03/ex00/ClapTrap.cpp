
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	if (DEBUG)
		std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->setName(name);
	this->setHitPoints(10);
	this->setEnergyPoints(10);
	this->setAttackDamage(0);
	if (DEBUG)
		std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &toCopy)
{
	*this = toCopy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &toCopy)
{
	if (this != &toCopy)
	{
		this->setName(toCopy.getName());
		this->setHitPoints(toCopy.getHitPoints());
		this->setEnergyPoints(toCopy.getEnergyPoints());
		this->setAttackDamage(toCopy.getAttackDamage());
	}
	return *this;
}

std::string	ClapTrap::getName() const
{
	return (this->name);
}

void	ClapTrap::setName(std::string name)
{
	this->name = name;
}

unsigned int	ClapTrap::getHitPoints() const
{
	return (this->HitPoints);
}

void	ClapTrap::setHitPoints(unsigned int Points)
{
	this->HitPoints = Points;
}

unsigned int	ClapTrap::getEnergyPoints() const
{
	return (this->EnergyPoints);
}

void	ClapTrap::setEnergyPoints(unsigned int Points)
{
	this->EnergyPoints = Points;
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return (this->AttackDamage);
}

void	ClapTrap::setAttackDamage(unsigned int Points)
{
	this->AttackDamage = Points;
}

ClapTrap::~ClapTrap(void)
{
	if (DEBUG)
		std::cout << "ClapTrap destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (!EnergyPoints)
	{
		std::cout << name << " has no energy points" << std::endl;
		return ;
	}
	std::cout << "ClapTrap "
				<< name
				<< " attacks "
				<< target
				<< " causing "
				<< AttackDamage
				<< " point of damage! "
				<< std::endl;
	setEnergyPoints(getEnergyPoints() - 1);
	// setHitPoints(getHitPoints() - getAttackDamage());
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->getEnergyPoints())
		this->setEnergyPoints(0);
	if (!getEnergyPoints() || !getHitPoints())
	{
		std::cout << name << " has no points" << std::endl;
		return ;
	}
	std::cout << name
				<< " take "
				<< amount
				<< " points of damage "
				<< std::endl;
	this->setHitPoints(this->getHitPoints() - amount);
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!getEnergyPoints() || !getHitPoints())
	{
		std::cout << name << " has no points" << std::endl;
		return ;
	}
	std::cout << name
				<< " has been repaired with "
				<< amount
				<< " points "
				<< std::endl;
	this->setHitPoints(getHitPoints() + amount);
	this->setEnergyPoints(getEnergyPoints() - 1);
}

void	ClapTrap::printClapTrapState()
{
	std::cout << "HitPoints: "
				<< this->getHitPoints()
				<< std::endl;
	std::cout << "EnergyPoints: "
				<< this->getEnergyPoints()
				<< "\n" << std::endl;
}
