#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "\t\t ==== First example ====" << std::endl;
	Bureaucrat A("First", 5);

	do{
		try {
			std::cout << A << std::endl;
			A.incrementGrade();
		}
		catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << "Caught an exception: " << e.what() << std::endl;
			break ;
		}
	} while (true);

	std::cout << "\t\t ==== Second example ====" << std::endl;
	try {
		Bureaucrat B("Second", 200);
		B.decrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "Caught an exception: " << e.what() << std::endl;
	}

	std::cout << "\t\t ==== Thirth example ====" << std::endl;
	Bureaucrat B("Thirth", 147);
	while (true) {
		try {
			std::cout << B << std::endl;
			B.decrementGrade();
		}
		catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << "Caught an exception: " << e.what() << std::endl;
			break;
		}
	}
}
