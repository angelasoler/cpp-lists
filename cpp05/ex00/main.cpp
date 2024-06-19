#include <iostream>
#include "Bureaucrat.cpp"

int	main()
{
	Bureaucrat	bureaucrat("bureaucrat");
	try
	{
		bureaucrat.setGrade(100);
	}
	catch (std::exception & e)
	{
		std::cout << "Exception " << e.what() << std::endl;
		// std::cout << "try again"<< std::endl;
	}
}
