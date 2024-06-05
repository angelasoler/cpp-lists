
#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

#ifndef DEBUG
#define DEBUG 0
#endif

class Harl
{
	private:
		Harl(void);
		~Harl(void);
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public:
		void	complain(std::string level);
};

#endif /* HARL_HPP */
