#include "AForm.hpp"
#include <iomanip>
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#define N_FORMS_KIND 3
// #define TestCannotExecuteException
#define TestTooLowException

#ifdef TestTooLowException
#define SignShrubberyCreation
// #define SignPresidentialPardom
// #define SignRobomyRequest
#endif

// Bureaucrats
Bureaucrat					HighGrade("HighGrade", 5);
Bureaucrat					LowMiddleGrade("LowMiddleGrade", 72);
Bureaucrat					HighMiddleGrade("HighMiddleGrade", 25);
Bureaucrat					LowGrade("LowGrade", 145);

//Forms
AForm						*forms[N_FORMS_KIND];
PresidentialPardonForm		PresidentPardon;
RobotomyRequestForm			RobotomyRequest;
ShrubberyCreationForm		ShrubberyCreation;

void	printFormsData()
{
	std::cout << "\n\t\t === See Forms ===\n" << std::endl;
	std::cout << "|" << std::setw(22) << "Name";
	std::cout << "|" << std::setw(17) << "Required to Sign";
	std::cout << "|" << std::setw(17) << "Require to Exec";
	std::cout << "|" << std::setw(12) << "Status";
	std::cout << "|" << std::endl;
	for (int i = 0; i < N_FORMS_KIND; i++)
		std::cout << *forms[i] << std::endl;
}

void	printInitData()
{
	PresidentPardon = PresidentialPardonForm("PresidentPardon Target");
	RobotomyRequest = RobotomyRequestForm("RobotomyRequest Target");
	ShrubberyCreation = ShrubberyCreationForm("ShrubberyCreation Target");

	forms[0] = &PresidentPardon;
	forms[1] = &RobotomyRequest;
	forms[2] = &ShrubberyCreation;

	std::cout << "\n\t\t === See Bureaucrats ===\n" << std::endl;
	std::cout << HighGrade << std::endl;
	std::cout << LowGrade << std::endl;
	std::cout << LowMiddleGrade << std::endl;
	std::cout << HighMiddleGrade << std::endl;
}

void	testTooLowException()
{
#ifdef SignPresidentialPardom
	std::cout << "\n\t\t === Signing and exec PresidentialPardonForm ===\n" << std::endl;
	PresidentPardon.beSigned(LowGrade);
	try
	{
		PresidentPardon.execute(LowGrade);
	}
	catch(GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";
	PresidentPardon.execute(LowMiddleGrade);
#endif

#ifdef SignRobomyRequest
	std::cout << "\n\t\t === Signing and exec RobotomyRequestForm ===\n" << std::endl;
	RobotomyRequest.beSigned(LowMiddleGrade);
	try
	{
		RobotomyRequest.execute(LowMiddleGrade);
	}
	catch(GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";
	RobotomyRequest.execute(HighMiddleGrade);
#endif
	
#ifdef SignShrubberyCreation
	std::cout << "\n\t\t === Signing and exec ShrubberyCreationForm ===\n" << std::endl;
	ShrubberyCreation.beSigned(HighMiddleGrade);
	try
	{
		ShrubberyCreation.execute(HighMiddleGrade);
	}
	catch(GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";
	ShrubberyCreation.execute(HighGrade);
#endif
}

void	testCannotExecuteException()
{
	std::cout << "\n\t\t === Test Cannot Execute Exception ===\n" << std::endl;
	try
	{
		PresidentPardon.execute(LowMiddleGrade);
	}
	catch(CannotExecuteException &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		RobotomyRequest.execute(HighMiddleGrade);
	}
	catch(CannotExecuteException &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		ShrubberyCreation.execute(HighGrade);
	}
	catch(CannotExecuteException &e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main()
{
	printInitData();
	printFormsData();
#ifdef TestCannotExecuteException
	testCannotExecuteException();
#endif
	testTooLowException();
	printFormsData();
}
