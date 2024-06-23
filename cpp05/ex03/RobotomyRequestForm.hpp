
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

#ifndef DEBUG
#define DEBUG 0
#endif

class RobotomyRequestForm : public AForm
{
	private:
		std::string	target;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
		~RobotomyRequestForm(void);
		std::string		getTarget(void) const;
		virtual	void	executeSpecificBehavior() const;
};

AForm			*createRobotomyRequest(const std::string &target);
#endif /* ROBOTOMYREQUESTFORM_HPP */
