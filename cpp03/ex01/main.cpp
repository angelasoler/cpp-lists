#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main( void ) {
	ClapTrap A("phil");
	ScavTrap B("Peter");

	A.setAttackDamage(2);
	A.printClapTrapState();
	B.printClapTrapState();


	A.attack("B");
	A.takeDamage(8);
	A.beRepaired(1);

	B.attack("A");
	B.takeDamage(8);
	B.beRepaired(1);

	std::cout << "\n" << std::endl;

	A.printClapTrapState();
	B.printClapTrapState();
}
