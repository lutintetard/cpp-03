#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	peter("Peter");
	ClapTrap	john("John");
	
	peter.attack("John");
	john.takeDamage(1);
	john.beRepaired(2);
	john.attack("Peter");
	peter.takeDamage(11);
	peter.beRepaired(5);
	return (0);
}
