
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
		Fixed(const Fixed &copy);
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
		friend std::ostream &operator<<(std::ostream& out, const Fixed& value);

		static Fixed	&min(Fixed &f1, Fixed &f2);
		static Fixed	&max(Fixed &f1, Fixed &f2);
		static const Fixed	&min(const Fixed &f1, const Fixed &f2);
		static const Fixed	&max(const Fixed &f1, const Fixed &f2);
};

#endif /* FIXED_HPP */
