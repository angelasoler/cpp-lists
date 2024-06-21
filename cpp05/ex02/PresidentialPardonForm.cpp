
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 145, 137)
{
	if (DEBUG)
		std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : target(target) {}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return this->target;
}

void PresidentialPardonForm::executeSpecificBehavior() const
{
	std::cout << getTarget()
		<< "has been pardoned by Zaphod Beeblebrox."
		<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
{
	if (DEBUG)
		std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (DEBUG)
		std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	if (this != &copy)
	{
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	if (DEBUG)
		std::cout << "PresidentialPardonForm destructor called" << std::endl;
}
