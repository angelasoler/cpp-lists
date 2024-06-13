#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#define N 2

int	main()
{
	// const Animal* pack[N];

	// int	i;
	// for (i = 0; i < N / 2; i++)
	// 	pack[i] = new Dog();
	// for (i = i; i < N; i++)
	// 	pack[i] = new Cat();
	// for (i = 0; i < N; i++)
	// 	pack[i]->makeSound();
	// delete[] *pack;

	// return 0;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	return 0;
}
