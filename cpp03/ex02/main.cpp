#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FlagTrap.hpp"
#include <iostream>

int main( void ) {
	ClapTrap BaseClass("dad");
	ScavTrap DerivateClass("son");
	FlagTrap DerivateFromDerivate("grandson");

	BaseClass.setAttackDamage(2);
	BaseClass.printClapTrapState();
	DerivateClass.printClapTrapState();
	DerivateFromDerivate.printClapTrapState();


	BaseClass.attack("Peter");
	BaseClass.takeDamage(8);
	BaseClass.beRepaired(1);

	DerivateClass.attack("phill");
	DerivateClass.takeDamage(8);
	DerivateClass.beRepaired(1);

	DerivateFromDerivate.attack("jhon");
	DerivateFromDerivate.takeDamage(8);
	DerivateFromDerivate.beRepaired(1);

	std::cout << "\n" << std::endl;

	BaseClass.printClapTrapState();
	DerivateClass.printClapTrapState();
	DerivateFromDerivate.printClapTrapState();

	DerivateClass.guardGate();
	DerivateFromDerivate.highFivesGuys();
}
