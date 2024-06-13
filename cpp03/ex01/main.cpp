#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main( void ) {
	ClapTrap BaseClass("phil");
	ScavTrap DerivateClass("Peter");

	BaseClass.setAttackDamage(2);
	BaseClass.printClapTrapState();
	DerivateClass.printClapTrapState();


	BaseClass.attack("Peter");
	BaseClass.takeDamage(8);
	BaseClass.beRepaired(1);

	DerivateClass.attack("phill");
	DerivateClass.takeDamage(8);
	DerivateClass.beRepaired(1);

	std::cout << "\n" << std::endl;

	BaseClass.printClapTrapState();
	DerivateClass.printClapTrapState();

	DerivateClass.guardGate();
}
