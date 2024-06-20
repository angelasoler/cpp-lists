#include "Form.hpp"

int	main()
{
	std::cout << "\t\t ==== Print form test ====" << std::endl;
	Bureaucrat	A("bureaucrat", 5);
	Form		Taxes("Taxes", 20, 20);

	std::cout << Taxes << std::endl;

	std::cout << "\n\t\t ==== Grade out of range test ====" << std::endl;
	try {
		Form	moreTaxes("more taxes", 200, 200);
	}
	catch (GradeTooLowException &e) {
		std::cout << "Caught an exception: " << e.what() << std::endl;
	}
	std::cout << "\t\t ==== Sign form example test ====" << std::endl;
	Taxes.beSigned(A);
	Taxes.signForm(A);
}
