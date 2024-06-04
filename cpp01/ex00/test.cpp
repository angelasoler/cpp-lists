#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include "Zombie.hpp"
#include "doctest.h"

TEST_CASE("check zombie announce")
{
	std::ostringstream output;
	std::streambuf    *p_cout_streambuf = std::cout.rdbuf();

	Zombie zombie1("<name>");
	std::cout.rdbuf(output.rdbuf());
	zombie1.announce();
	std::cout.rdbuf(p_cout_streambuf);
	CHECK_EQ(output.str(), "<name>: BraiiiiiiinnnzzzZ...\n");

	output.str("");
	output.clear();

	Zombie zombie2("Foo");
	std::cout.rdbuf(output.rdbuf());
	zombie2.announce();
	std::cout.rdbuf(p_cout_streambuf);
	CHECK_EQ(output.str(), "Foo: BraiiiiiiinnnzzzZ...\n");
}
