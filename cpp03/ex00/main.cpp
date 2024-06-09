#include "ClapTrap.hpp"
#include <iostream>

int main( void ) {
	ClapTrap A("phil");

	A.setAttackDamage(2);
	A.printClapTrapState();

	A.attack("B");
	A.takeDamage(8);
	A.beRepaired(1);

	std::cout << "\n" << std::endl;

	A.printClapTrapState();
}
