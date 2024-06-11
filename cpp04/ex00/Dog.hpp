
#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

#ifndef DEBUG
#define DEBUG 0
#endif

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog &copy);
		virtual Dog &operator=(const Dog &copy);
		~Dog(void);
		void	makeSound(void) const;
};

#endif /* DOG_HPP */
