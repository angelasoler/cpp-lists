
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	if (DEBUG)
		std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name) : name(name) {}

std::string	Bureaucrat::getName() const
{
	return (name);
}

int	Bureaucrat::getGrade() const
{
	return (grade);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
};

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
};

void	Bureaucrat::setGrade(const int &grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 50)
		throw GradeTooLowException();
	this->grade = grade;
}


Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name)
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
		setName(copy.name);
		setGrade(copy.grade);
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
