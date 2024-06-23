
#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#ifndef DEBUG
#define DEBUG 0
#endif

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &copy);
		Intern &operator=(const Intern &copy);
		~Intern(void);

		AForm *makeForm(std::string FormName, std::string FormTarget);
};

#endif /* INTERN_HPP */
