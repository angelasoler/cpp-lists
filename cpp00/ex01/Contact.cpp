
#include "Contact.hpp"

Contact::Contact(){}

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
		ret = ft_atoi(input);
	}
	return (ret);
}

std::string	SetField(std::string output)
{
	std::string					input;
	std::string::const_iterator	it;
	std::string					result;

	while (input.empty()) {
		std::cout << output;
		std::getline(std::cin, input);
		it = input.begin();
		while (it != input.end()) {
			if (!std::isspace(*it))
				result += *it;
			it++;
		}
		if (result.empty())
			input.clear();
		else
			input = result;
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
