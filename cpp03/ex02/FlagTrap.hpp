
#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include <iostream>
#include "ScavTrap.hpp"

#ifndef DEBUG
#define DEBUG 0
#endif

class FlagTrap : public ScavTrap
{
	private:	
	public:
		FlagTrap(void);
		FlagTrap(std::string name);
		~FlagTrap(void);

		void	highFivesGuys(void);
};

#endif /* FLAGTRAP_HPP */
