
#include "Intern.hpp"
#define TYPES 3

Intern::Intern(void)
{
	if (DEBUG)
		std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	if (DEBUG)
		std::cout << "Intern copy constructor called" << std::endl;
	*this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
	if (DEBUG)
		std::cout << "Intern copy assignment operator called" << std::endl;
	if (this != &copy)
	{
	}
	return *this;
}

Intern::~Intern(void)
{
	if (DEBUG)
		std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::makeForm(std::string FormName, std::string FormTarget)
{
	std::string	Forms[TYPES] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm		*(*funcPtr[TYPES])(const std::string &target) = {&createPresidentialPardon,
																&createRobotomyRequest,
																&createShrubberyCreationForm};

	for (short i = 0; i < TYPES; i++)
	{
		if (FormName == Forms[i])
			return ((*funcPtr[i])(FormTarget));
	}
	std::cerr << "Error: Invalid name" << std::endl;
	return (NULL);
}
