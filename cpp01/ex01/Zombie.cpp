
#include "Zombie.hpp"

Zombie::Zombie()
{
	if (DEBUG)
		std::cout << "Zombie default constructor called" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << ": memory liberated" << std::endl;
	if (DEBUG)
		std::cout << "Zombie destructor called" << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->name
			<< ": BraiiiiiiinnnzzzZ..."
			<< std::endl;
}
