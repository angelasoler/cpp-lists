
#ifndef CONTACT_HPP
#define CONTACT_HPP

#ifndef N_CONTACTS
#define N_CONTACTS 8
#endif

#include <iostream>


class Contact
{
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		int			phonenumber;
		std::string	darkest_secret;
		void	SetFirtsName(string name);
	private:
};

#endif /* CONTACT_HPP */
