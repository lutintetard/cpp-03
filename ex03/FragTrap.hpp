#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include <iostream>

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(std::string const &name);
	FragTrap(FragTrap const &other);
	~FragTrap(void);
	FragTrap &operator=(FragTrap const &other); 
	void	highFivesGuys(void);
private:
	int	high;	
};

#endif
