#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap(std::string const &name);
	DiamondTrap(DiamondTrap const &other);
	~DiamondTrap(void);
	DiamondTrap &operator=(DiamondTrap const &other); 
	using ScavTrap::attack;
	void	whoAmI(void);
private:
	std::string	name;
};

#endif
