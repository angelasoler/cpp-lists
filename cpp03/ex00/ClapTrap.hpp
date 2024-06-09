
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#ifndef DEBUG
#define DEBUG 1
#endif

class ClapTrap
{
	private:
		std::string		name;
		unsigned int	HitPoints;
		unsigned int	EnergyPoints;
		unsigned int	AttackDamage;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		ClapTrap &operator=(const ClapTrap &copy);
		~ClapTrap(void);

		std::string			getName() const;
		void				setName(std::string name);
		unsigned int		getHitPoints() const;
		void				setHitPoints(unsigned int Points);
		unsigned int		getEnergyPoints() const;
		void				setEnergyPoints(unsigned int Points);
		unsigned int		getAttackDamage() const;
		void				setAttackDamage(unsigned int Points);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	printClapTrapState();
};

#endif /* CLAPTRAP_HPP */
