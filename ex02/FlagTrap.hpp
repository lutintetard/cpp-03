#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FlagTrap : public ClapTrap
{
public:
	FlagTrap(std::string const &name);
	FlagTrap(FlagTrap const &other);
	~FlagTrap(void);
	FlagTrap &operator=(FlagTrap const &other); 
	void	highFivesGuys(void);
private:
	int	high;	
};

#endif
