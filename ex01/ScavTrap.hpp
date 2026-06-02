#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(std::string const &name);
	ScavTrap(ScavTrap const &other);
	~ScavTrap(void);
	ScavTrap &operator=(ScavTrap const &other); 
	void	attack(std::string const &name);
	void	guardGate(void);	
private:
	bool	guard;
};

#endif
