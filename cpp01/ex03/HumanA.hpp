
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

#ifndef DEBUG
#define DEBUG 0
#endif

class HumanA
{
	private:
		std::string	name;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		Weapon	&weapon;
		void	attack();
};

#endif /* HUMANA_HPP */
