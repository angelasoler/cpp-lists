
#ifndef CONTACT_HPP
#define CONTACT_HPP

#ifndef N_CONTACTS
#define N_CONTACTS 8
#endif

#include <iostream>
#include <string>


class Contact
{
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		long		phonenumber;
		std::string	darkest_secret;
		Contact();
		void	fill_contact_fields();
	private:
};

#endif /* CONTACT_HPP */
