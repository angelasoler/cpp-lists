
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45)
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : target(target) {}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return this->target;
}

void RobotomyRequestForm::executeSpecificBehavior() const
{
	std::cout << "Whirr whirr whirr Bzzzzzz... "
			<< getTarget()
			<< "has been robotomized successfully."
			<< std::endl;
}

AForm	*createRobotomyRequest(const std::string &target)
{
	RobotomyRequestForm	staticForm;
	RobotomyRequestForm	*form;

	staticForm = RobotomyRequestForm(target);
	form = new RobotomyRequestForm(staticForm);
	return form;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm(copy)
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this != &copy)
		this->target = copy.getTarget();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm destructor called" << std::endl;
}
