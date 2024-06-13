
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

#ifndef DEBUG
#define DEBUG 0
#endif

#define N_IDEAS 100

class Brain
{
	private:
		std::string	ideas[N_IDEAS];
	public:
		Brain(void);
		Brain(const Brain &copy);
		Brain &operator=(const Brain &copy);
		~Brain(void);
};

#endif /* BRAIN_HPP */
