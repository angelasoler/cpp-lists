#include "Intern.hpp"


int	main()
{
	Intern	someRandomIntern;
	AForm	*rrf;

	std::cout << "|" << std::setw(22) << "Name";
	std::cout << "|" << std::setw(17) << "Required to Sign";
	std::cout << "|" << std::setw(17) << "Require to Exec";
	std::cout << "|" << std::setw(12) << "Status";
	std::cout << "|" << std::setw(12) << "Target";
	std::cout << "|" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf;
	std::cout << std::setw(12) << dynamic_cast<RobotomyRequestForm*>(rrf)->getTarget();
	std::cout << "|" << std::endl;
	delete rrf;
}
