
#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

#ifndef DEBUG
#define DEBUG 0
#endif

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat &copy);
		virtual Cat &operator=(const Cat &copy);
		~Cat(void);
		void	makeSound(void) const;
};

#endif /* CAT_HPP */
