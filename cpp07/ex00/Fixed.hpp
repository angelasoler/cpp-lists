
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <climits>

#ifndef DEBUG
#define DEBUG 0
#endif

class Fixed
{
	private:
		int					fixedPoint;
		static const int	franctionBits = 8;
	public:
		Fixed(void);
		Fixed(const int n);
		Fixed(const float f);
		Fixed(const Fixed &toCopy);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt() const;
		float	toFloat() const;

		Fixed	&operator=(const Fixed &fp);
		bool	operator<(const Fixed &fp);
		bool	operator>(const Fixed &fp);
		bool	operator<=(const Fixed &fp);
		bool	operator>=(const Fixed &fp);
		bool	operator==(const Fixed &fp);
		bool	operator!=(const Fixed &fp);

		Fixed	operator+(const Fixed &fp);
		Fixed	operator-(const Fixed &fp);
		Fixed	operator*(const Fixed &fp);
		Fixed	operator/(const Fixed &fp);
		
		Fixed	operator++();
		Fixed	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
};

std::ostream &operator<<(std::ostream& out, const Fixed& value);

#endif /* FIXED_HPP */
