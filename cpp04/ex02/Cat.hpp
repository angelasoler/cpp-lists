
#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

#ifndef DEBUG
#define DEBUG 0
#endif

class Cat : public AAnimal
{
	private:
		Brain		*brain;
	public:
		Cat(void);
		Cat(const Cat &copy);
		Cat &operator=(const Cat &copy);
		~Cat(void);
		Brain*	getBrain() const;
		void	makeSound(void) const;
};

#endif /* CAT_HPP */
