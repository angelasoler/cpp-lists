
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

#ifndef DEBUG
#define DEBUG 0
#endif

class ScavTrap : public ClapTrap
{
	private:
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		~ScavTrap(void);

		void guardGate();
		void	attack(const std::string& target);
};

#endif /* SCAVTRAP_HPP */
