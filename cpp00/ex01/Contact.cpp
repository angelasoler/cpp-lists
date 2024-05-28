
#include "Contact.hpp"

Contact::Contact(){}

long	is_number(const std::string& n)
{
	long	result = 0;

	if (n.empty())
		return (0);
	for (int i = 0; i < (int)n.size(); i++) {
		if (n[i] < '0' || n[i] > '9') {
			std::cout << "Invalid input, try again please" << std::endl;
			return (0);
		}
		int digit = n[i] - 48;
		result = result * 10 + digit;
	}

	return (result);
}

int	SetNumericField(std::string output)
{
	std::string	input;
	int			ret = 0;

	while (!ret) {
		std::cout << output;
		std::getline(std::cin, input);
		if (input.size() > 16) {
			std::cout << "Number is too long, 15 digits is the limit, try again please" << std::endl;
			continue;
		}
		ret = is_number(input);
	}
	return (ret);
}

std::string	SetField(std::string output)
{
	std::string	input;

	while (input.empty()) {
		std::cout << output;
		std::getline(std::cin, input);
	}
	return (input);
}

void	Contact::fill_contact_fields()
{
	std::cout << "ATENTION: No field could be empty!" << std::endl;
	this->first_name = SetField("First Name:");
	this->last_name = SetField("Last Name:");
	this->nickname = SetField("Nickname:");
	this->phonenumber = SetNumericField("Phonenumber:");
	this->darkest_secret = SetField("Darkest Secret:");
}
