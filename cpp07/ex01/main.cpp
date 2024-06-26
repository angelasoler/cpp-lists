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
	Bureaucrat	A[] = {Bureaucrat("A", 5), Bureaucrat("B", 6)};
	Form		forms[] = {Form("Taxes", 20, 20), Form("Presidential pardon", 35, 70)};

	::iter(A, 2, printMember<Bureaucrat>);
	::iter(forms, 2 , printMember<Form>);

}
