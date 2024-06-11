
#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

#ifndef DEBUG
#define DEBUG 0
#endif

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog(void);
		Dog(const Dog &copy);
		Dog	&operator=(const Dog &copy);
		~Dog(void);
		void	makeSound(void) const;
};

#endif /* DOG_HPP */
