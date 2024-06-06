
#include "Fixed.hpp"

Fixed::Fixed(void)
{
	if (DEBUG)
		std::cout << "Fixed constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	if (DEBUG)
		std::cout << "Fixed copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	if (DEBUG)
		std::cout << "Fixed copy assignment operator called" << std::endl;
	if (this != &copy)
	{
	}
	return *this;
}

Fixed::~Fixed(void)
{
	if (DEBUG)
		std::cout << "Fixed destructor called" << std::endl;
}
