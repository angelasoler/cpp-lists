
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <limits>
#include <cstdlib>
#include <cstdio>

#ifndef DEBUG
#define DEBUG 0
#endif

typedef enum
{
	CHAR = 1,
	INT,
	FLOAT,
	DOUBLE
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
