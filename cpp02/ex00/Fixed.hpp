
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

#ifndef DEBUG
#define DEBUG 0
#endif

class Fixed
{
	private:
	public:
		Fixed(void);
		Fixed(const Fixed &copy);
		Fixed &operator=(const 	S &copy);
		~Fixed(void);
};

#endif /* FIXED_HPP */
