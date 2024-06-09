
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

Fixed	&Fixed::operator=(const Fixed &toCopy)
{
	if (DEBUG)
		std::cout << "Copy assignment operator called" << std::endl;
	if (this != &toCopy)
	{
		this->fixedPoint =  toCopy.getRawBits();
	}
	return *this;
}

bool	Fixed::operator<(const Fixed &fp)
{
	if (fixedPoint < fp.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>(const Fixed &fp)
{
	if (fixedPoint > fp.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &fp)
{
	if (fixedPoint <= fp.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &fp)
{
	if (fixedPoint >= fp.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &fp)
{
	if (fixedPoint == fp.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &fp)
{
	if (fixedPoint != fp.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator+(const Fixed &fp)
{
	Fixed result;

	result.setRawBits(this->getRawBits() + fp.getRawBits());
	return (result);
	return (Fixed(this->getRawBits() + fp.getRawBits()));
}

Fixed	Fixed::operator-(const Fixed &fp)
{
	Fixed result;

	result.setRawBits(this->getRawBits() - fp.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed &fp)
{
	Fixed	result;
	long int raw = this->getRawBits() * fp.getRawBits();

	raw += (1 << (franctionBits - 1));
	raw = raw >> franctionBits;
	if (raw > INT_MAX)
		raw = INT_MAX;
	if (raw < INT_MIN)
		raw = INT_MIN;
	result.setRawBits(raw);
	return (result);
}

Fixed	Fixed::operator/(const Fixed &fp)
{
	Fixed	result;
	long int raw = this->getRawBits();

	raw = raw << franctionBits;
	raw = raw + (fp.getRawBits() >> 1);

	result.setRawBits(raw / fp.getRawBits());
	return (result);
}

Fixed	Fixed::operator++()
{
	this->setRawBits(getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->setRawBits(getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed result = *this;

	this->setRawBits(getRawBits() + 1);
	return (result);
}

Fixed	Fixed::operator--(int)
{
	Fixed result = *this;

	this->setRawBits(getRawBits() - 1);
	return (result);
}

Fixed::~Fixed(void)
{
	if (DEBUG)
		std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	if (DEBUG)
		std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	if (DEBUG)
		std::cout << "setRawBits member function called" << std::endl;
	this->fixedPoint = raw;
}

int	Fixed::toInt() const
{
	return (this->fixedPoint >> this->franctionBits);
}

float	Fixed::toFloat() const
{
	return static_cast<float>(this->fixedPoint) / (1 << this->franctionBits);
}

std::ostream &operator<<(std::ostream& out, const Fixed& value)
{
	out << value.toFloat();
	return out;
}

Fixed&	Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed&	Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed&	Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed&	Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}
