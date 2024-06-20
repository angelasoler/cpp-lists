
#include "AForm.hpp"

AForm::AForm(void) : isSigned(false), gradeRequireSign(0), gradeRequireExec(0)
{
	if (DEBUG)
		std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int gradeRequireSign, const int gradeRequireExec) :
	name(name), gradeRequireSign(gradeRequireSign), gradeRequireExec(gradeRequireExec)
{
	isSigned = false;
	if ((gradeRequireSign > 150 || gradeRequireSign < 1) || \
		(gradeRequireExec > 150 || gradeRequireExec < 1))
		throw GradeTooLowException("Grade require to sign out of range\n");
}

AForm::AForm(const AForm &copy) :
name(copy.name), gradeRequireSign(copy.gradeRequireSign), gradeRequireExec(copy.gradeRequireExec)
{
	if (DEBUG)
		std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &copy)
{
	if (DEBUG)
		std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &copy)
	{
	}
	return *this;
}

AForm::~AForm(void)
{
	if (DEBUG)
		std::cout << "AForm destructor called" << std::endl;
}

const std::string	AForm::getName(void) const
{
	return name;
}

int	AForm::getRequireGradeSing(void) const
{
	return gradeRequireSign;
}

int	AForm::getRequireGradeExec(void) const
{
	return gradeRequireExec;
}

bool	AForm::getIsSigned(void) const
{
	return isSigned;
}

void	AForm::setIsSigned(bool isSigned)
{
	this->isSigned = isSigned;
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeRequireSign) {
		std::string msg = bureaucrat.getName() + " grade is too low.";
		throw GradeTooLowException(msg.c_str());
	}
	else
		isSigned = true;
}

void	AForm::signForm(Bureaucrat &bureaucrat)
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

std::ostream	&operator<<(std::ostream& out, AForm &form)
{
	out << form.getName()
		<< " require grade "
		<< form.getRequireGradeSing()
		<< " to be signed and grade "
		<< form.getRequireGradeExec()
		<< " to be executed. AForm "
		<< (form.getIsSigned()? " is signed." : " isn't signed.");
	return out;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw (CannotExecuteException());
	if (executor.getGrade() < getRequireGradeExec())
		throw (GradeTooLowException("Grade too low to execute this form!"));
}

CannotExecuteException::CannotExecuteException(void) {}

CannotExecuteException::~CannotExecuteException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {}

const char *CannotExecuteException::what() const throw()
{
	return ("Cannot execute the form cause it is not signed");
}
