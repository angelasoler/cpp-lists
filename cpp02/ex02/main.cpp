#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;


	Fixed f1(0B11);
	Fixed f2(0B10);

	std::cout << "1) " << ((f1 > f2)? "SUCESS":"FAIL") << std::endl;
	std::cout << "2) " << ((f1 < f2)? "FAIL":"SUCESS") << std::endl;
	std::cout << "3) " << ((f1 > f2)? "SUCESS":"FAIL") << std::endl;
	std::cout << "4) " << ((f1 < f2)? "FAIL":"SUCESS") << std::endl;
	Fixed f3(0B10);
	std::cout << "5) " << ((f1 >= f2)? "SUCESS":"FAIL") << std::endl;
	std::cout << "6) " << ((f2 >= f3)? "SUCESS":"FAIL") << std::endl;
	std::cout << "7) " << ((f1 < f2)? "FAIL":"SUCESS") << std::endl;
	std::cout << "8) " << ((f2 < f3)? "FAIL":"SUCESS") << std::endl;

	f1.setRawBits(0B10);
	f2.setRawBits(0B11);
	f3.setRawBits(0B11);
	std::cout << "9) " << ((f1 <= f2)? "SUCESS":"FAIL") << std::endl;
	std::cout << "10) " << ((f2 <= f3)? "SUCESS":"FAIL") << std::endl;
	std::cout << "11) " << ((f1 > f2)? "FAIL":"SUCESS") << std::endl;
	std::cout << "12) " << ((f2 > f3)? "FAIL":"SUCESS") << std::endl;
	std::cout << "13) " << ((f2 == f3)? "SUCESS":"FAIL") << std::endl;
	std::cout << "14) " << ((f2 != f3)? "FAIL":"SUCESS") << std::endl;
	std::cout << "15) " << ((f1 != f2)? "SUCESS":"FAIL") << std::endl;
	std::cout << "16) " << ((f1 == f2)? "FAIL":"SUCESS") << std::endl;

	return 0;
}
