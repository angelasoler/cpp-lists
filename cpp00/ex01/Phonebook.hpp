#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>

#ifndef DEBUG
#define DEBUG 0
#endif

class Phonebook
{
  public:
	Phonebook(void);
	Phonebook(const Phonebook &copy);
	Phonebook &operator=(const Phonebook &copy);
	~Phonebook(void);

  private:
};

#endif /* PHONEBOOK_HPP */
