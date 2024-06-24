
#include "ScalarConverter.hpp"
#define N_TYPES 4

const std::string	floatTypes[N_TYPES] = {"inff", "+inff", "-inff", "nanf"};

std::string	LITERAL;
double		positive_inf = std::numeric_limits<double>::infinity();
double		negative_inf = -std::numeric_limits<double>::infinity();
double		nan_value = std::numeric_limits<double>::quiet_NaN();
double		pseudoList[4] = {positive_inf, positive_inf, negative_inf, nan_value};
double		pseudoRet;
char		literalChar = 0;
int			literalInt = 0;
double		literalDouble = 0;
float		literalFloat = 0;

ScalarConverter::ScalarConverter(void)
{
	if (DEBUG)
		std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	if (DEBUG)
		std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	if (DEBUG)
		std::cout << "ScalarConverter copy assignment operator called" << std::endl;
	if (this != &copy)
	{
	}
	return *this;
}

ScalarConverter::~ScalarConverter(void)
{
	if (DEBUG)
		std::cout << "ScalarConverter destructor called" << std::endl;
}

void	isImpossible(void)
{
	std::cout << "Impossible convertion." << std::endl;
	exit (1);
}

types	verifyPseudoFloatTypes()
{
	for (int i = 0; i < N_TYPES; ++i) {
		if (floatTypes[i] == LITERAL) {
			pseudoRet = pseudoList[i];
			return (PSEUDO);
		}
	}
	return (INVALID);
}

types	isInt()
{
	char* endptr;
	long value = strtol(LITERAL.c_str(), &endptr, 10);

	if (*endptr != '\0')
		return (INVALID);
	literalDouble = static_cast<double> (value);
	literalFloat = static_cast<float> (value);
	if (value > INT_MAX || value < INT_MIN)
		return (OVERLOAD);
	else {
		literalInt = value;
		return (INT);
	}
}

types	isDecimal()
{
	char* endptr;
	double value = strtod(LITERAL.c_str(), &endptr);

	if (*endptr != '\0')
		return (verifyPseudoFloatTypes());
	if (value > DBL_MAX || value < -DBL_MAX) {
		pseudoRet = value;
		return (PSEUDO);
	}
	literalDouble = value;
	literalFloat = static_cast<float> (literalDouble);
	literalInt = static_cast<int> (literalDouble);
	if (value > INT_MAX || value < INT_MIN)
		return (OVERLOAD);
	else
		return (DOUBLE);
}

types	isNumber()
{
	types	intType = isInt();

	if (intType == OVERLOAD)
		return (OVERLOAD);
	else if (intType == INT)
		return (INT);
	else
		return (isDecimal());
	return (INVALID);
}

types	isLiteral(void)
{
	if (LITERAL.length() == 1 && !std::isdigit(LITERAL[0]))
	{
		literalChar = LITERAL[0];
		literalInt = static_cast<int> (*LITERAL.c_str());
		literalDouble = static_cast<double> (*LITERAL.c_str());
		literalFloat = static_cast<float> (*LITERAL.c_str());
		return (CHAR);
	}
	return (isNumber());
}

void	ScalarConverter::convert(std::string literal)
{
	LITERAL = literal;
	types	type = isLiteral();

	switch (type)
	{
		case PSEUDO:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << static_cast<float>(pseudoRet)
				<< "f" << std::endl;
			std::cout << "double: " << pseudoRet << std::endl;
			return ;
		case OVERLOAD:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: overload" << std::endl;
			break;
		case INVALID:
			isImpossible();
		default:
			if (literalInt >= 0 && literalInt <= 127) {
				literalChar = static_cast<char> (literalInt);
				if (!isprint(literalInt))
					std::cout << "char: Non displayable" << std::endl;
				else
					std::cout << "char: " << literalChar << std::endl;
			}
			else
				std::cout << "char: impossible" << std::endl;
	}
	if (type != PSEUDO && type != OVERLOAD)
		std::cout << "int: " << literalInt << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(6)
				<< std::setfill('0') << static_cast<float>(literalFloat)
				<< "f" << std::endl;
	std::cout << "double: " << literalDouble << std::endl;
}
