
#include "Base.hpp"

Base::~Base(void)
{
	if (DEBUG)
		std::cout << "Base destructor called" << std::endl;
}
