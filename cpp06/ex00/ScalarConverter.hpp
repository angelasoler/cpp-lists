
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <limits>
#include <climits>
#include <float.h>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iomanip>

#ifndef DEBUG
#define DEBUG 0
#endif

typedef enum
{
	INVALID,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	OVERLOAD,
	PSEUDO
}	types;

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &copy);
	public:
		ScalarConverter &operator=(const ScalarConverter &copy);
		~ScalarConverter(void);
		static void	convert(std::string literal);
};


#endif /* SCALARCONVERTER_HPP */
