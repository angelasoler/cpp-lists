#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class Phonebook
{
	public:
		int	Command(void);
		int	size;
	private:
		Contact	contacts[N_CONTACTS];
		int		AddAContact(void);
		void	DisplayContactsList(void);
		void	DisplayContactByIndex(void);
};

#endif /* PHONEBOOK_HPP */
