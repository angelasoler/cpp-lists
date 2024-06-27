#include "Array.hpp"
#include "Bureaucrat.hpp"

#define PRIMITIVE_TESTS

void classesArrayTests()
{
	::Array<Bureaucrat> A(5);
	::Array<Bureaucrat> B;

	A.initMembers(Bureaucrat("none", 0));
	B.initMembers(Bureaucrat("none", 0));
	std::cout << "A size: " << A.size() << std::endl;
	std::cout << "B size: " << B.size() << std::endl;
	B = A; // using over load =
	::Array<Bureaucrat> C(A); // using cpy constructor
	std::cout << "A size: " << A.size() << std::endl;
	std::cout << "B size: " << B.size() << std::endl;
	std::cout << "C size: " << C.size() << std::endl;
	std::cout << "\t\t\t====== B =====" << std::endl;
	std::cout << "\t\t====== Trying to set data out of bounds =====" << std::endl;
	try
	{
		B[2] = Bureaucrat("Taxes", 20);
		B[3] = Bureaucrat("Taxes", 20);
		C[0] = Bureaucrat("Presidential pardon", 35);
		C[1] = Bureaucrat("Presidential pardon", 35);
		C[2] = Bureaucrat("Presidential pardon", 35);
		B[7] = Bureaucrat("Presidential pardon", 35);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\t\t\t====== A =====" << std::endl;
	printMembers(A);
	std::cout << "\t\t\t====== B =====" << std::endl;
	printMembers(B);
	std::cout << "\t\t\t====== C =====" << std::endl;
	printMembers(C);
}

int	main()
{
#ifdef PRIMITIVE_TESTS
	::Array<int> A(5);
	::Array<int> B;

	A.initMembers(0);
	B.initMembers(0);
	std::cout << "\t\t\t====== B =====" << std::endl;
	printMembers(B);
	std::cout << "A size: " << A.size() << std::endl;
	std::cout << "B size: " << B.size() << std::endl;
	B = A; // using over load =
	::Array<int> C(A); // using cpy constructor
	std::cout << "A size: " << A.size() << std::endl;
	std::cout << "B size: " << B.size() << std::endl;
	std::cout << "C size: " << C.size() << std::endl;
	std::cout << "\t\t\t====== B =====" << std::endl;
	std::cout << "\t\t====== Trying to set data out of bounds =====" << std::endl;
	try
	{
		B[2] = 5;
		B[3] = 5;
		C[0] = 42;
		C[1] = 42;
		C[2] = 42;
		B[7] = 5;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\t\t\t====== A =====" << std::endl;
	printMembers(A);
	std::cout << "\t\t\t====== B =====" << std::endl;
	printMembers(B);
	std::cout << "\t\t\t====== C =====" << std::endl;
	printMembers(C);
#else
	classesArrayTests();
#endif
}
