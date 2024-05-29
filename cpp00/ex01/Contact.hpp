
#ifndef CONTACT_HPP
#define CONTACT_HPP

#ifndef N_CONTACTS
#define N_CONTACTS 8
#endif

#include <iostream>
#include <string>
#include "utils.hpp"


class Contact
{
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		long		phonenumber;
		std::string	darkest_secret;
		long		is_number(const std::string& n);
		void		fill_contact_fields();
		Contact();
	private:
};

#endif /* CONTACT_HPP */
