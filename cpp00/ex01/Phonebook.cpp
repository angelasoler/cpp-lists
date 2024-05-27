#include "Phonebook.hpp"

void	fill_contact_field(int index)
{
	Contact contact;
	std::string	input;

	std::cout << "this would be contact n " << index << std::endl;
	std::cout << "First Name:";
	std::getline(std::cin, input);
	contacts[index] = contact;
	contact.SetFirstName(input);
	std::cout << "Last Name:" << std::endl;
	std::getline(std::cin, input);
	std::cout << "Nickname:" << std::endl;
	std::getline(std::cin, input);
	std::cout << "Darkest Secret:" << std::endl;
	std::getline(std::cin, input);
}

void	AddAContact(void)
{
	static int	current_contact_index;
	std::string	input;

	std::getline(std::cin, input);
	fill_contact_field(current_contact_index);
	std::cout << "$ I know you wanna add a contact, but wait is wip" << std::endl;
	current_contact_index++;
	if (current_contact_index >= N_CONTACTS)
		current_contact_index = 0;
}

void	DisplayAContact(void)
{
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
	std::cout << "$ Nothing to search still" << std::endl;
}

int Phonebook::Command(void)
{
	std::string cmd;

	std::getline(std::cin, cmd);
	if (cmd == "ADD")
		AddAContact();
	else if (cmd == "SEARCH")
		DisplayAContact();
	else if (cmd == "EXIT")
		return (1);
	else
		std::cout << "Try again with a valid command please" << std::endl;
	return (0);
}
