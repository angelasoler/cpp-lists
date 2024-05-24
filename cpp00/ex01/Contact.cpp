
#include "Contact.hpp"

Contact::Contact(void)
{
	if (DEBUG)
		std::cout << "Contact default constructor called" << std::endl;
}

Contact::Contact(const Contact &copy)
{
	if (DEBUG)
		std::cout << "Contact copy constructor called" << std::endl;
	*this = copy;
}

Contact &Contact::operator=(const Contact &copy)
{
	if (DEBUG)
		std::cout << "Contact copy assignment operator called" << std::endl;
	if (this != &copy)
	{
	}
	return *this;
}

Contact::~Contact(void)
{
	if (DEBUG)
		std::cout << "Contact destructor called" << std::endl;
}
