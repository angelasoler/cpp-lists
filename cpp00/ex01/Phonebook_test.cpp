#include "Phonebook.hpp"
#include "doctest.h"

TEST_SUITE("Class Phonebook")
{
	TEST_CASE("Phonebook Canonical Form")
	{
		Phonebook obj1;
		Phonebook obj2(obj1);
		Phonebook obj3 = obj2;
	}
}
