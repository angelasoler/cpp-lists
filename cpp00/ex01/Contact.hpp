
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

#ifndef DEBUG
#define DEBUG 0
#endif

class Contact
{
  public:
	Contact(void);
	Contact(const Contact &copy);
	Contact &operator=(const Contact &copy);
	~Contact(void);

  private:
};

#endif /* CONTACT_HPP */
