
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include "Contact.hpp"
#include "Phonebook.hpp"
#include "utils.hpp"
#include "doctest.h"


TEST_SUITE("Utils")
{
	TEST_CASE("Truncate field, 10 character wide")
	{
		CHECK_EQ(truncated_field("I have more than 10 charater wide"), "I have mo.");
	}
}
