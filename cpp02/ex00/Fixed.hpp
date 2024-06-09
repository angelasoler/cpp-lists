
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

#ifndef DEBUG
#define DEBUG 1
#endif

class Fixed
{
	private:
		int					number;
		static const int	fraction = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &toCopy);
		Fixed &operator=(const Fixed &toCopy);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif /* FIXED_HPP */
