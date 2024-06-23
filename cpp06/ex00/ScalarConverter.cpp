
#include "ScalarConverter.hpp"
#define N_TYPES 4

const std::string floatTypes[N_TYPES] = {"inff", "+inff", "-inff", "nanf"};
const std::string doubleTypes[N_TYPES] = {"inf", "+inf", "-inf", "nan"};
std::string 	LITERAL;


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

const types	isPseudo(void)
{
	for (int i = 0; i < N_TYPES; ++i)
		if (floatTypes[i] == LITERAL)
			return FLOAT;
		else if (doubleTypes[i] == LITERAL)
			return DOUBLE;
	return (0);
}

void	isImpossible(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
	exit (1);
}

const types	isLiteral(void)
{
	if (LITERAL.length() == 1 & !std::isdigit(LITERAL[0]))
		return (CHAR);
	else if ()
}



void	ScalarConverter::convert(std::string literal)
{
	LITERAL = literal;
	const types	&type = isPseudo()? isPseudo() : isLiteral();

	isImpossible();


	;
	


	float floatValue = static_cast<float>(std::atof(literal.c_str()));

	// Verifica se o float é um número inteiro
	bool isInteger = (floatValue == static_cast<int>(floatValue));

	// Formata a saída
	char buffer[50]; // Buffer para armazenar a string formatada
	if (isInteger) {
		std::sprintf(buffer, "float: %.1f", floatValue); // Caso seja um inteiro
	} else {
		std::sprintf(buffer, "float: %f", floatValue); // Caso contrário
	}
	int intValue = std::atoi(literal.c_str());
	char charValue;

	if (intValue >= 0 && intValue <= 127) {
		charValue = static_cast<char>(intValue);
		if (std::isprint(charValue)) {
			std::cout << "char: '" << charValue << "'" << std::endl;
		} else {
			std::cout << "char: Non displayable" << std::endl;
		}
	} else {
		std::cout << "char: impossible" << std::endl;
	}

	std::cout << "int: " << intValue << std::endl;

	// float floatValue = static_cast<float>(intValue);
	std::cout << "float: " << floatValue << "f" << std::endl;

	double doubleValue = static_cast<double>(intValue);
	std::cout << "double: " << doubleValue << std::endl;
}
