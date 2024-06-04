#include "Zombie.hpp"

int main()
{
	Zombie *heapZombie = newZombie("Heap Zombie");
	Zombie  stackZombie("Stack Zombie");

	heapZombie->announce();
	stackZombie.announce();
	randomChump("Stack zombie by function");
	delete heapZombie;
}