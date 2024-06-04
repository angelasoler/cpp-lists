#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include "HumanB.hpp"
#include "HumanA.hpp"
#include "Weapon.hpp"
#include "doctest.h"

TEST_CASE("class Weapon")
{
	Weapon weapon("Pistol");

	CHECK_EQ(weapon.getType(), "Pistol");
	weapon.setType("Shotgun");
	CHECK_EQ(weapon.getType(), "Shotgun");
}

TEST_CASE("class HumanA")
{
	std::ostringstream oss;
	std::streambuf    *p_cout_streambuf = std::cout.rdbuf();

	Weapon weapon("Pistol");
	HumanA humanA("Bob", weapon);

	CHECK_EQ(weapon.getType(), "Pistol");
	weapon.setType("Shotgun");
	CHECK_EQ(weapon.getType(), "Shotgun");

	std::cout.rdbuf(oss.rdbuf());
	humanA.attack();
	std::cout.rdbuf(p_cout_streambuf);
	CHECK_EQ(oss.str(), "Bob attacks with their Shotgun\n");
	oss.str("");
	oss.clear();
}

TEST_CASE("class HumanB")
{
	std::ostringstream oss;
	std::streambuf    *p_cout_streambuf = std::cout.rdbuf();

	Weapon weapon("Pistol");
	HumanB humanB("Bob");

	std::cout.rdbuf(oss.rdbuf());
	humanB.attack();
	std::cout.rdbuf(p_cout_streambuf);
	CHECK_EQ(oss.str(), "Bob cannot attack, he has no weapon!\n");
	oss.str("");
	oss.clear();

	humanB.setWeapon(weapon);

	std::cout.rdbuf(oss.rdbuf());
	humanB.attack();
	std::cout.rdbuf(p_cout_streambuf);
	CHECK_EQ(oss.str(), "Bob attacks with their Pistol\n");
	oss.str("");
	oss.clear();

	CHECK_EQ(weapon.getType(), "Pistol");
	weapon.setType("Shotgun");
	CHECK_EQ(weapon.getType(), "Shotgun");

	std::cout.rdbuf(oss.rdbuf());
	humanB.attack();
	std::cout.rdbuf(p_cout_streambuf);
	CHECK_EQ(oss.str(), "Bob attacks with their Shotgun\n");
	oss.str("");
	oss.clear();
}
