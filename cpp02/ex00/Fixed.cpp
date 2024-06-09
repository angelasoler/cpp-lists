
#include "Fixed.hpp"

Fixed::Fixed(void)
{
	if (DEBUG)
		std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(const Fixed &toCopy)
{
	if (DEBUG)
		std::cout << "Copy constructor called" << std::endl;
	*this = toCopy;
}

Fixed &Fixed::operator=(const Fixed &toCopy)
{
	if (DEBUG)
		std::cout << "Copy assignment operator called" << std::endl;
	if (this != &toCopy)
	{
		this->number =  toCopy.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(void)
{
	if (DEBUG)
		std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->number);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->number = raw;
}
