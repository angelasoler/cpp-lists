#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include "Fixed.hpp"
#include "doctest.h"

TEST_CASE("check")
{
	Fixed const b(Fixed( 5.05f ) * Fixed( 2 ));

	CHECK_EQ((b.toFloat()), 10.1016f);
}

TEST_CASE("Test rawBits of Class Fixed")
{
	Fixed fixed = Fixed(1);
	CHECK_EQ(fixed.getRawBits(), 0B100000000);
	fixed = Fixed(1.1f); // 1.0001100110011001101
	CHECK_EQ(fixed.getRawBits(), 0B100011010);
}

TEST_CASE("Arithmetic operators of Class Fixed")
{
	SUBCASE("+")
	{
		Fixed f1(1);
		Fixed f2(1);
		Fixed f3 = f1 + f2;

		CHECK_EQ(f3.toInt(), 2);
	}
	SUBCASE("-")
	{
		Fixed f1(3);
		Fixed f2(2);
		Fixed f3 = f1 - f2;

		CHECK_EQ(f3.toInt(), 1);
	}
	SUBCASE("*")
	{
		Fixed f1(2);
		Fixed f2(2);
		Fixed f3 = f1 * f2;

		CHECK_EQ(f3.toInt(), 4);

		f1 = Fixed(1.5f);
		f2 = Fixed(1.5f);
		f3 = f1 * f2;

		CHECK_EQ(f3.toFloat(), 2.25f);
	}
	SUBCASE("/")
	{
		Fixed f1(2);
		Fixed f2(2);
		Fixed f3 = f1 / f2;

		CHECK_EQ(f3.toInt(), 1);

		// (n1 << _bits) / n2

		f1 = Fixed(4);
		f2 = Fixed(1.6f);
		f3 = f1 / f2; // == 2.5f
		CHECK_GT(f3.toFloat(), 2.4f);
		CHECK_LE(f3.toFloat(), 2.5f);
	}
}
