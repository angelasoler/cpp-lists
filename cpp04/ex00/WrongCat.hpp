#ifndef WrongCat_HPP
#define WrongCat_HPP

#include <iostream>
#include "WrongAnimal.hpp"

#ifndef DEBUG
#define DEBUG 0
#endif

class WrongCat : public WrongAnimal
{
	private:
	public:
		WrongCat(void);
		~WrongCat(void);
		void	makeSound(void) const;
};

#endif /* CAT_HPP */
