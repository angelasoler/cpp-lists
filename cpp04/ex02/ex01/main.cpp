#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#define N 2
// #define __DEBUG__

void	baseClassTest() {
#ifdef __DEBUG__
	std::cout << std::endl;
	std::cout << "base Tests" << std::endl;
	std::cout << "========" << std::endl;
	const Animal* rigthAnimal = new Animal();

	rigthAnimal->makeSound();
	std::cout << rigthAnimal->getType() << " " << std::endl;
#endif
}

void	deepCpyTest()
{
#ifdef __DEBUG__
	std::cout << std::endl;
	std::cout << "Cpy Tests" << std::endl;
	std::cout << "========" << std::endl;
	Cat	A;
	std::cout << std::endl;
	A.getBrain()->setIdea(0, "cats have ideas?");
	Cat Aux = A;
	std::cout << std::endl;
	Cat B;
	std::cout << std::endl;
	B = A;
	std::cout << std::endl;

	A.getBrain()->setIdea(0, "meoww meowww thas's all i can think");
	std::cout << A.getBrain() << std::endl;
	std::cout << Aux.getBrain()<< std::endl;
	std::cout << A.getBrain()->getIdea(0) << std::endl;
	std::cout << Aux.getBrain()->getIdea(0) << std::endl;
	std::cout << B.getBrain()->getIdea(0) << std::endl;
#endif
}

int	main()
{
#ifndef __DEBUG__
	const Animal* pack[N];

	int	i;
	std::cout << "Dog Packs" << std::endl;
	std::cout << std::endl;
	for (i = 0; i < N / 2; i++)
		pack[i] = new Dog();

	std::cout << std::endl;
	std::cout << "Cat Packs" << std::endl;
	std::cout << std::endl;
	for (i = i; i < N; i++)
		pack[i] = new Cat();
	std::cout << std::endl;

	for (i = 0; i < N; i++)
		pack[i]->makeSound();
	std::cout << std::endl;
	for (i = 0; i < N; i++)
		delete pack[i];
	std::cout << std::endl;
#endif
	deepCpyTest();
	baseClassTest();
	std::cout << std::endl;
	return 0;
}
