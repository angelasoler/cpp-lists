
#include "Form.hpp"

Form::Form(void) : isSigned(false), gradeRequireSign(0), gradeRequireExec(0)
{
	if (DEBUG)
		std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, const int gradeRequireSign, const int gradeRequireExec) :
	name(name), gradeRequireSign(gradeRequireSign), gradeRequireExec(gradeRequireExec)
{
	isSigned = false;
	if ((gradeRequireSign > 150 || gradeRequireSign < 1) || \
		(gradeRequireExec > 150 || gradeRequireExec < 1))
		throw GradeTooLowException("Grade require to sign out of range\n");
}

Form::Form(const Form &copy) :
name(copy.name), gradeRequireSign(copy.gradeRequireSign), gradeRequireExec(copy.gradeRequireExec)
{
	if (DEBUG)
		std::cout << "Form copy constructor called" << std::endl;
	*this = copy;
}

Form &Form::operator=(const Form &copy)
{
	if (DEBUG)
		std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &copy)
	{
	}
	return *this;
}

Form::~Form(void)
{
	if (DEBUG)
		std::cout << "Form destructor called" << std::endl;
}

const std::string	Form::getName(void)
{
	return name;
}

int	Form::getRequireGradeSing(void)
{
	return gradeRequireSign;
}

int	Form::getRequireGradeExec(void)
{
	return gradeRequireExec;
}

bool	Form::getIsSigned(void)
{
	return isSigned;
}

void	Form::setIsSigned(bool isSigned)
{
	this->isSigned = isSigned;
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeRequireSign) {
		std::string msg = bureaucrat.getName() + " grade is too low.";
		throw GradeTooLowException(msg.c_str());
	}
	else
		setIsSigned(true);
}

void	Form::signForm(Bureaucrat &bureaucrat)
{
	if (isSigned) {
		std::cout << bureaucrat.getName()
				<< " signed " << getName()
				<< std::endl;
	}
	else {
		std::cout << bureaucrat.getName() << " couldn’t sign " << getName()
					<< " because minimum grade " << getRequireGradeSing()
					<< " is require." << std::endl;
	}
}

std::ostream	&operator<<(std::ostream& out, Form &form)
{
	out << form.getName()
		<< " require grade "
		<< form.getRequireGradeSing()
		<< " to be signed and grade "
		<< form.getRequireGradeExec()
		<< " to be executed. Form "
		<< (form.getIsSigned()? " is signed." : " isn't signed.");
	return out;
}
