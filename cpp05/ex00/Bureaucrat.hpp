
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#ifndef DEBUG
#define DEBUG 0
#endif

class Bureaucrat
{
	private:
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		~Bureaucrat(void);
};

std::ostream	&operator<<(std::ostream& out, Bureaucrat &bureaucrat);

#endif /* BUREAUCRAT_HPP */
