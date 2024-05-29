#include "Phonebook.hpp"

int	Phonebook::AddAContact()
{
	static int	current_contact_index;
	std::string	input;

	if (this->size == N_CONTACTS)
		current_contact_index = 0;
	this->contacts[current_contact_index].fill_contact_fields();
	if (this->size < N_CONTACTS) {
		this->size = current_contact_index + 1;
		current_contact_index++;
	}
	return (0);
}

void	Phonebook::DisplayContactByIndex()
{
	std::string	input;
	int			index = 0;

	while (!index || index > this->size || index > N_CONTACTS) {
		std::cout << "See by Index(1-8):" << std::endl;
		getline(std::cin, input);
		index = ft_atoi(input);
		if (!index)
			std::cout << "Invalid index, try again" << std::endl;
		else if (index > N_CONTACTS)
			std::cout << "Out of range index, try again" << std::endl;
		else if (index > this->size)
			std::cout << "Empty index, try again" << std::endl;
	}
	std::cout << "First Name: ";
	std::cout << this->contacts[index - 1].first_name << std::endl;
	std::cout << "Last Name: ";
	std::cout << this->contacts[index - 1].last_name << std::endl;
	std::cout << "Nickname: ";
	std::cout << this->contacts[index - 1].nickname << std::endl;
	std::cout << "Phonenumber: ";
	std::cout << this->contacts[index - 1].phonenumber << std::endl;
	std::cout << "Darkest Secret: ";
	std::cout << this->contacts[index - 1].darkest_secret << std::endl;
	std::cout << "\n" << std::endl;
}

void	Phonebook::DisplayContactsList(void)
{
	std::cout << "|" << std::right << std::setw(10) << truncated_field("Index");
	std::cout << "|" << std::setw(10) << truncated_field("First Name");
	std::cout << "|" << std::setw(10) << truncated_field("Last Name");
	std::cout << "|" << std::setw(10) << truncated_field("Nickname");
	std::cout << "|" << std::setw(10) << truncated_field("Phonenumber");
	std::cout << "|" << std::setw(10) << truncated_field("Darkest Secret");
	std::cout << "|" << std::endl;
	for (int i = 0; i < this->size; i++) {
		std::cout << "|" << std::setw(10) << i + 1;
		std::cout << "|" << std::setw(10)
				<< truncated_field(this->contacts[i].first_name);
		std::cout << "|" << std::setw(10)
				<< truncated_field(this->contacts[i].last_name);
		std::cout << "|" << std::setw(10)
				<< truncated_field(this->contacts[i].nickname);
		std::cout << "|" << std::setw(10)
				<< truncated_field(ft_itoa(this->contacts[i].phonenumber));
		std::cout << "|" << std::setw(10)
				<< truncated_field(this->contacts[i].darkest_secret);
		std::cout << "|" << std::endl;
	}
	std::cout << "\n" << std::endl;
}

int Phonebook::Command(void)
{
	std::string	cmd;
	static int	count_entries;

	if (count_entries%5 == 0 && count_entries != 0) {
		std::cout << "\tREMEMBER!" << std::endl;
		InitInstructions();
	}
	std::getline(std::cin, cmd);
	if (cmd == "ADD") {
		std::cout << "\n" << std::endl;
		if (this->AddAContact())
			std::cout << "Fail saving contact" << std::endl;
		else
			std::cout << "Contact was saved successfully" << std::endl;
		std::cout << "\n" << std::endl;
	}
	else if (cmd == "SEARCH") {
		std::cout << "\n" << std::endl;
		if (!this->size) {
			std::cout << "There's no contacts in your phonebook" << std::endl;
			return (0);
		}
		this->DisplayContactsList();
		this->DisplayContactByIndex();
		std::cout << "\n" << std::endl;
	}
	else if (cmd == "EXIT")
		return (1);
	else
		std::cout << "Try again with a valid command please" << std::endl;
	count_entries++;
	return (0);
}
