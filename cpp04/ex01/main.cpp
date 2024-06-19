#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#define N 2
#define __DEBUG__

void	baseClassTest() {
#ifdef __DEBUG__
	const Animal* rigthAnimal = new Animal();

	rigthAnimal->makeSound();
	std::cout << rigthAnimal->getType() << " " << std::endl;
#endif
}

int	main()
{
	const Animal* pack[N];

	int	i;
	for (i = 0; i < N / 2; i++)
		pack[i] = new Dog();
	for (i = i; i < N; i++)
		pack[i] = new Cat();
	for (i = 0; i < N; i++)
		pack[i]->makeSound();
	for (i = 0; i < N; i++)
		delete pack[i];
	baseClassTest();
	return 0;
}
