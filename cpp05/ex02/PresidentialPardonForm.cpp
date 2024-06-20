
#include "PresidentialPardonForm.hpp"
// Create a file <target>_shrubbery in the working directory, and writes ASCII trees
// inside it.

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("ShrubberyCreationForm", 145, 137)
{
	if (DEBUG)
		std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : target(target) {}

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
