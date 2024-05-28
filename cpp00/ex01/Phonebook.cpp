#include "Phonebook.hpp"

int	Phonebook::AddAContact()
{
	static int	current_contact_index;
	std::string	input;

	std::cout << "current index" << current_contact_index << std::endl;
	this->contacts[current_contact_index].fill_contact_fields();
	current_contact_index++;
	this->size = current_contact_index;
	if (current_contact_index >= N_CONTACTS) {
		current_contact_index = 0;
		this->size = N_CONTACTS;
	}
	return (0);
}


// TO-DO
// [_] tratar output, 10 chars limited
// [_] make Dysplat contact by index
void	Phonebook::DisplayContactsList(void)
{
	std::cout << "|";
	std::cout << std::setw(10) << "Index";
	std::cout << "|";
	std::cout << std::setw(10) << "First Name";
	std::cout << "|";
	std::cout << std::setw(10) << "Last Name";
	std::cout << "|";
	std::cout << std::setw(10) << "Nickname";
	std::cout << "|";
	std::cout << std::setw(10) << "Phonenumb.";
	std::cout << "|";
	std::cout << std::setw(10) << "Darkest S.";
	std::cout << "|" << std::endl;
	for (int i = 0; i < this->size; i++) {
		std::cout << "|";
		std::cout << std::setw(10) << i + 1;
		std::cout << "|";
		std::cout << std::setw(10) << this->contacts[i].first_name;
		std::cout << "|";
		std::cout << std::setw(10) << this->contacts[i].last_name;
		std::cout << "|";
		std::cout << std::setw(10) << this->contacts[i].nickname;
		std::cout << "|";
		std::cout << std::setw(10) << this->contacts[i].phonenumber;
		std::cout << "|";
		std::cout << std::setw(10) << this->contacts[i].darkest_secret;
		std::cout << "|" << std::endl;
	}
	int index = 0;
	while (!index || index > 8) {
		std::cout << "See by Index(1-8):" << std::endl;
		getline(cin, input);
		index = is_number(input);
	}
	DysplayContactByIndex(index);
}

int Phonebook::Command(void)
{
	std::string cmd;

	std::getline(std::cin, cmd);
	if (cmd == "ADD") {
		if (this->AddAContact())
			std::cout << "Fail saving contact" << std::endl;
		else
			std::cout << "Contact was saved successfully" << std::endl;
	}
	else if (cmd == "SEARCH")
		this->DisplayContactsList();
	else if (cmd == "EXIT")
		return (1);
	else
		std::cout << "Try again with a valid command please" << std::endl;
	return (0);
}
