#include <iostream>
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	const Animal* rigthAnimal = new Animal();
	const Animal* rigthDog = new Dog();
	const Animal* rigthCat = new Cat();
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << std::endl;

	std::cout << rigthDog->getType() << " " << std::endl;
	std::cout << rigthCat->getType() << " " << std::endl;
	rigthCat->makeSound(); //will output the cat sound!
	rigthDog->makeSound();
	rigthAnimal->makeSound();
	std::cout << rigthAnimal->getType() << " " << std::endl;

	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();
	wrongAnimal->makeSound();
	std::cout << wrongAnimal->getType() << " " << std::endl;

	delete rigthAnimal;
	delete rigthDog;
	delete rigthCat;
	delete wrongAnimal;
	delete wrongCat;
	return 0;
}
