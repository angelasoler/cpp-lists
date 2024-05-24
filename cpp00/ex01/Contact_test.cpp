
#include "Contact.hpp"
#include "doctest.h"

TEST_SUITE("Class Contact")
{
	TEST_CASE("Orthodox Canonical Form")
	{
		Contact obj1;
		Contact obj2(obj1);
		Contact obj3 = obj2;
	}
}
