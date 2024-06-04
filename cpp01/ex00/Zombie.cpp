
#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
	if (DEBUG)
		std::cout << "Zombie default constructor called" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << ": memory liberated" << std::endl;
	if (DEBUG)
		std::cout << "Zombie destructor called" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->name
			<< ": BraiiiiiiinnnzzzZ..."
			<< std::endl;
}
