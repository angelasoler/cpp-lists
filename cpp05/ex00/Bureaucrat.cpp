
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	if (DEBUG)
		std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	setGrade(grade);
}

std::string	Bureaucrat::getName(void) const
{
	return (name);
}

void	Bureaucrat::incrementGrade()
{
	int	newGrade = getGrade() - 1;
	setGrade(newGrade);
}

void	Bureaucrat::decrementGrade()
{
	int	newGrade = getGrade() + 1;
	setGrade(newGrade);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw GradeTooLowException("150 is the lowest possible grade\n");
	if (grade < 1)
		throw GradeTooHighException("1 is the highest possible grade\n");
	this->grade = grade;
}

int		Bureaucrat::getGrade(void) const
{
	return (grade);
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
		this->setGrade(copy.getGrade());
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

Bureaucrat::GradeTooLowException::GradeTooLowException(const char *msg) : msg(msg) {}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char *msg) : msg(msg) {}
