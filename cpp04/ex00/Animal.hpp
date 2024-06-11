
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#ifndef DEBUG
#define DEBUG 1
#endif

class Animal
{
	protected:
		std::string type;
	public:
		Animal(void);
		Animal(const Animal &copy);
		Animal &operator=(const Animal &copy);
		virtual ~Animal(void);
		virtual void	makeSound(void) const;
		void			setType(std::string type);
		std::string		getType() const;
};

#endif /* ANIMAL_HPP */
