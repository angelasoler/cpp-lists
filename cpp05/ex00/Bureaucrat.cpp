
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	if (DEBUG)
		std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	if (DEBUG)
		std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (DEBUG)
		std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		
	}
	return *this;
}

std::ostream	&operator<<(std::ostream& out, Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName()
		<< ", bureaucrat grade "
		<< bureaucrat.getGrade()
		<< std::endl;
	return out;
}

Bureaucrat::~Bureaucrat(void)
{
	if (DEBUG)
		std::cout << "Bureaucrat destructor called" << std::endl;
}
