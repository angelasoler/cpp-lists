#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class Phonebook
{
	public:
		int		Command(void);
	private:
		Contact contacts[N_CONTACTS];
};

#endif /* PHONEBOOK_HPP */
