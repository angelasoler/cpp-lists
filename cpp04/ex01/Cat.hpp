
#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

#ifndef DEBUG
#define DEBUG 0
#endif

class Cat : public Animal
{
	private:
		Brain		*brain;
	public:
		Cat(void);
		Cat(const Cat &copy);
		Cat &operator=(const Cat &copy);
		~Cat(void);
		void	makeSound(void) const;
};

#endif /* CAT_HPP */
