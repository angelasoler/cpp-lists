
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

#ifndef DEBUG
#define DEBUG 0
#endif

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie();
		~Zombie(void);
		void	announce(void);
		void	set_name(std::string name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif /* ZOMBIE_HPP */
