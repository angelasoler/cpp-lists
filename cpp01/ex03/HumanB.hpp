
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

#ifndef DEBUG
#define DEBUG 0
#endif

class HumanB
{
	private:
		std::string	name;
	public:
		HumanB(std::string name);
		~HumanB(void);
		Weapon	*weapon;
		void	attack();
		void	setWeapon(Weapon &weapon);
};

#endif /* HUMANB_HPP */
