
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

#ifndef DEBUG
#define DEBUG 0
#endif

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
		~PresidentialPardonForm(void);
		std::string		getTarget(void) const;
		virtual void	executeSpecificBehavior() const;
};

AForm		*createPresidentialPardon(const std::string &target);

#endif /* PRESIDENTIALPARDONFORM_HPP */
