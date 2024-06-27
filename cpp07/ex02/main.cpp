#include "Array.hpp"

int	main()
{
	::Array<int> A(5);
	::Array<int> B;


	initMembers(A);
	initMembers(B);
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
		B.setData(5, 2);
		B.setData(5, 3);
		C.setData(42, 0);
		C.setData(42, 1);
		C.setData(42, 2);
		B.setData(5, 7);
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
