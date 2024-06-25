#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>

Base	*generate(void)
{
	srand(time(0)); 
	int	randClass = rand();


	std::cout << (randClass % 3) << std::endl;
	switch(randClass % 3) {
		case a:
			return (new A());
		case b:
			return (new B());
		case c:
			return (new C());
		default:
			std::cerr << "Error: rand out of range" << std::endl;
			exit (1);
	}
	return NULL;
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "This object is type A: ";
	else if (dynamic_cast<B *>(p))
		std::cout << "This object is type B: ";
	else if (dynamic_cast<C *>(p))
		std::cout << "This object is type C: ";
	std::cout << p << std::endl;
}

void	identify(Base &p)
{
	try {
		A &foo = dynamic_cast<A &>(p);
		std::cout << "This object is type A: ";
		std::cout << &foo << std::endl;
	}
	catch (std::exception &e){
	}
	try {
		B &bar = dynamic_cast<B &>(p);
		std::cout << "This object is type B" << std::endl;
		std::cout << &bar << std::endl;
	}
	catch (std::exception &e){
	}
	try {
		C &baz = dynamic_cast<C &>(p);
		std::cout << "This object is type C" << std::endl;
		std::cout << &baz << std::endl;
	}
	catch (std::exception &e){
	}
}


int	main()
{
	Base *foo = generate();
	Base &ref = *foo;

	identify(foo);
	identify(ref);
	delete foo;
}
