
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

#ifndef DEBUG
#define DEBUG 0
#endif

class Weapon
{
	private:
		std::string	type;
	public:
		Weapon(std::string type);
		~Weapon(void);
		const std::string&	getType();
		void				setType(std::string type);
};

#endif /* WEAPON_HPP */
