
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

#ifndef DEBUG
#define DEBUG 0
#endif

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal &operator=(const WrongAnimal &copy);
		~WrongAnimal(void);
		void	makeSound(void) const;
		void			setType(std::string type);
		std::string		getType() const;
};

#endif /* WRONGANIMAL_HPP */
