#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <cstdlib>
# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

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
