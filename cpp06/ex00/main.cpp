#include "ScalarConverter.hpp"


// double positive_inf = std::numeric_limits<double>::infinity();
// double negative_inf = -std::numeric_limits<double>::infinity();
// double nan_value = std::numeric_limits<double>::quiet_NaN();

int	main(int argc, char *argv[])
{
	if (argc != 2)
		std::cerr << "error: bad arguments" << std::endl;
	ScalarConverter::convert(argv[1]);
}
