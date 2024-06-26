#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include "doctest.h"
#include "ScalarConverter.hpp"


TEST_SUITE("Utils")
{
	TEST_CASE("convertion")
	{
		LITERAL = "nan";
		CHECK_EQ(isLiteral(), PSEUDO);
		LITERAL = "inf";
		CHECK_EQ(isLiteral(), PSEUDO);
		LITERAL = "-inf";
		CHECK_EQ(isLiteral(), PSEUDO);
		LITERAL = "+inf";
		CHECK_EQ(isLiteral(), PSEUDO);
		LITERAL = "nanf";
		CHECK_EQ(isLiteral(), PSEUDO);
		LITERAL = "inff";
		CHECK_EQ(isLiteral(), PSEUDO);
		LITERAL = "-inff";
		CHECK_EQ(isLiteral(), PSEUDO);
		LITERAL = "+inff";
		CHECK_EQ(isLiteral(), PSEUDO);
		LITERAL = "6";
		CHECK_EQ(isLiteral(), INT);
		LITERAL = "878787677867876876";
		CHECK_EQ(isLiteral(), OVERLOAD);
		LITERAL = "42.0f";
		CHECK_EQ(isLiteral(), DOUBLE);
		LITERAL = "a";
		CHECK_EQ(isLiteral(), CHAR);
		LITERAL = "dfksjkd";
		CHECK_EQ(isLiteral(), INVALID);
		LITERAL = "42.0fkhjh";
		CHECK_EQ(isLiteral(), INVALID);
		LITERAL = "42jkjsdf";
		CHECK_EQ(isLiteral(), INVALID);
		LITERAL = "0";
		CHECK_EQ(isLiteral(), INT);
	}
}