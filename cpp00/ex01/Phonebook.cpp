#include "Phonebook.hpp"

// TO-DO
// [_] usar a função de contact e apagar a duplicada (is_number)
static long	is_number(const std::string& n)
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

// [_] formatar tabela 10 char limited
void	Phonebook::DisplayContactByIndex()
{
	std::string	input;
	int index = 0;

	while (!index || index > this->size || index > 8) {
		std::cout << "See by Index(1-8):" << std::endl;
		getline(std::cin, input);
		index = is_number(input);
	}

	std::cout << "First Name" << std::endl;
	std::cout << this->contacts[index - 1].first_name << std::endl;
	std::cout << "Last Name" << std::endl;
	std::cout << this->contacts[index - 1].last_name << std::endl;
	std::cout << "Nickname" << std::endl;
	std::cout << this->contacts[index - 1].nickname << std::endl;
	std::cout << "Phonenumber" << std::endl;
	std::cout << this->contacts[index - 1].phonenumber << std::endl;
	std::cout << "Darkest Secret" << std::endl;
	std::cout << this->contacts[index - 1].darkest_secret << std::endl;
}

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
	else if (cmd == "SEARCH") {
		if (!this->size) {
			std::cout << "There's no contacts in your phonebook" << std::endl;
			return (0);
		}
		this->DisplayContactsList();
		this->DisplayContactByIndex();
	}
	else if (cmd == "EXIT")
		return (1);
	else
		std::cout << "Try again with a valid command please" << std::endl;
	return (0);
}
