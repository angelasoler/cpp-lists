
#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

#define LEVELS 4

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
};

#endif /* HARL_HPP */
