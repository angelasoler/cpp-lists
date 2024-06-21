
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

#ifndef DEBUG
#define DEBUG 0
#endif

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm(void);
		std::string		getTarget(void) const;
		virtual void	executeSpecificBehavior() const;
};

#endif /* SHRUBBERYCREATIONFORM_HPP */
