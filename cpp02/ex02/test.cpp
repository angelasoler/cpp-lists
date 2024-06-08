#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include "Fixed.hpp"
#include "doctest.h"

TEST_CASE("check")
{
	Fixed a;
	Fixed b(10);
	Fixed c(42.42f);
	Fixed d(b);

	a = Fixed(1234.4321f);
	CHECK_EQ(a.toFloat(), 1234.43f);
	CHECK_EQ(b.toFloat(), 10);
	CHECK_EQ(c.toFloat(), 42.4219f);
	CHECK_EQ(d.toFloat(), 10);

	CHECK_EQ(a.toInt(), 1234);
	CHECK_EQ(b.toInt(), 10);
	CHECK_EQ(c.toInt(), 42);
	CHECK_EQ(d.toInt(), 10);

}
