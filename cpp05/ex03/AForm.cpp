
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
		std::string msg = bureaucrat.getName() + " grade is too low to sign.";
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
	out << "|" << std::setw(22) << form.getName()
		<< "|" << std::setw(17) << form.getRequireGradeSing()
		<< "|" << std::setw(17) << form.getRequireGradeExec()
		<< "|" << std::setw(12) << (form.getIsSigned()? " Signed" : " Not Signed")
		<< "|";
	return out;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw (CannotExecuteException());
	if (executor.getGrade() > getRequireGradeExec()) {
		std::cerr << "|" << std::setw(22) << "Name";
		std::cerr << "|" << std::setw(4) << "Grade";
		std::cerr << "|" << std::endl;
		std::cerr << "|" << std::setw(22) << executor.getName();
		std::cerr << "|" << std::setw(4) << executor.getGrade();
		std::cerr << "|" << std::endl;
		std::cerr << "|" << std::setw(22) << getName();
		std::cerr << "|" << std::setw(4) << getRequireGradeExec();
		std::cerr << "|" << std::endl;
		throw (GradeTooLowException("Grade too low to execute this form!"));
	}
	executeSpecificBehavior();
}

CannotExecuteException::CannotExecuteException(void) {}

CannotExecuteException::~CannotExecuteException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {}

const char *CannotExecuteException::what() const throw()
{
	return ("Cannot execute the form cause it is not signed");
}
