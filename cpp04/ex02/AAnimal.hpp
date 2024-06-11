
#ifndef AAnimal_HPP
#define AAnimal_HPP

#include <iostream>

#ifndef DEBUG
#define DEBUG 1
#endif

class AAnimal
{
	protected:
		std::string	type;
	public:
		AAnimal(void);
		AAnimal(const AAnimal &copy);
		virtual AAnimal &operator=(const AAnimal &copy);
		virtual ~AAnimal(void);
		virtual void	makeSound(void) const = 0;
		void			setType(std::string type);
		std::string		getType() const;
};

#endif /* AAnimal_HPP */
