
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

#ifndef DEBUG
#define DEBUG 1
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
		Fixed &operator=(const Fixed &copy);
		friend std::ostream &operator<<(std::ostream& out, const Fixed& value);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt() const;
		float	toFloat() const;
};

#endif /* FIXED_HPP */
