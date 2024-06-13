
#include "Fixed.hpp"

Fixed::Fixed(void)
{
	if (DEBUG)
		std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(const int n)
{
	if (DEBUG)
		std::cout << "Int constructor called" << std::endl;
	this->setRawBits(n << franctionBits);
}

Fixed::Fixed(const float f)
{
	if (DEBUG)
		std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(f * (1 << this->franctionBits)));
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
		this->fixedPoint =  toCopy.getRawBits();
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
	return (this->fixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPoint = raw;
}

int	Fixed::toInt() const
{
	return (this->fixedPoint  >> this->franctionBits);
}

float	Fixed:: toFloat() const
{
	return static_cast<float>(this->fixedPoint) / (1 << this->franctionBits);
}

std::ostream &operator<<(std::ostream& out, const Fixed& value)
{
	out << value.toFloat();
	return out;
}
