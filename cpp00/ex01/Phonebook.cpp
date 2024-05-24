#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	if (DEBUG)
		std::cout << "Phonebook default constructor called" << std::endl;
}

Phonebook::Phonebook(const Phonebook &copy)
{
	if (DEBUG)
		std::cout << "Phonebook copy constructor called" << std::endl;
	*this = copy;
}

Phonebook &Phonebook::operator=(const Phonebook &copy)
{
	if (DEBUG)
		std::cout << "Phonebook copy assignment operator called" << std::endl;
	if (this != &copy)
	{
	}
	return *this;
}

Phonebook::~Phonebook(void)
{
	if (DEBUG)
		std::cout << "Phonebook destructor called" << std::endl;
}
