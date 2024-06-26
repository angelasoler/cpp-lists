#include "iter.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "\t\t===== primitive types =====" << std::endl;
	int		array[] = {1, 2, 3, 4, 5};
	char	arraychar[] = {97, 98, 99, 100, 101};

	::iter(array, 5 , printMember<int>);
	::iter(arraychar, 5 , printMember<char>);

	std::cout << "\t\t===== Objects Class =====" << std::endl;
	Bureaucrat	A("A", 5);
	Form		Taxes("Taxes", 20, 20);

	std::cout << Taxes << std::endl;
	std::cout << A << std::endl;
}
