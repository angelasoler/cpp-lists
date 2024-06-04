#include "Zombie.hpp"
#define HORDE_SIZE 300
#define HORDE_NAME "Head horde"

int main()
{
	unsigned char	horde_size = (unsigned char)HORDE_SIZE;
	std::string		zombies_name = HORDE_NAME;
	Zombie			*horde = zombieHorde((int)horde_size, zombies_name);

	for (int i = 0; i < horde_size; i++) {
		horde[i].announce();
	}
	delete[] horde;
}