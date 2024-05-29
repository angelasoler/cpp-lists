#include "utils.hpp"

void	InitInstructions(void)
{
	std::cout << std::endl;
	std::cout << "- There is just these 3 commands:" << std::endl;
	std::cout << std::endl;
	std::cout << "|" << std::left << std::setw(10) << "COMMAND";
	std::cout << "|" << std::setw(45) << "DESCRIPTION";
	std::cout << "|" << std::endl;
	std::cout << "|" << std::setw(10) << "ADD";
	std::cout << "|" << std::setw(45) << "add a contact to your phonebook";
	std::cout << "|" << std::endl;
	std::cout << "|" << std::setw(10) << "SEARCH";
	std::cout << "|" << std::setw(45) << "See your phonebook state, and search by index";
	std::cout << "|" << std::endl;
	std::cout << "|" << std::setw(10) << "EXIT";
	std::cout << "|" << std::setw(45) << "Exit the program";
	std::cout << "|" << std::endl;
	std::cout << std::endl;
}

std::string	truncated_field(std::string src)
{
	std::string	dest;
	int			src_size;

	src_size = src.size();
	dest = src;
	if (src_size > 10)
		dest[10] = '\0';
	if (src_size > 9) {
		dest[9] = '.';
		dest.resize(10);
	}
	return (dest);
}

std::string	ft_itoa(long n)
{
	std::string	result;
	int			size;

	while (n > 0) {
		int digit = n % 10;
		result.push_back(digit + '0');
		n /= 10;
	}
	size = result.size();
	for (int i = 0; i < size / 2; i++) {
		std::swap(result[i], result[size - i - 1]);
	}
	return result;
}

long	ft_atoi(const std::string& n)
{
	long	result = 0;

	if (n.empty())
		return (0);
	for (std::string::const_iterator it = n.begin(); it != n.end(); it++) {
		if (*it < '0' || *it > '9') {
			std::cout << "Invalid input, try again please" << std::endl;
			return (0);
		}
		int digit = *it - '0';
		result = result * 10 + digit;
	}

	return (result);
}
