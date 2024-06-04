#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zombie = new Zombie[N];

	if (DEBUG)
		std::cout << "Zombie horde is a ["
				<< N << "] gangue" << std::endl;
	for (int i = 0; i < N; i++)
	{
		if (DEBUG)
			std::cout << i;
		zombie[i].set_name(name);
	}
	return (zombie);
}
