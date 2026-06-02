#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FlagTrap.hpp"

int	main(void)
{
	ClapTrap	peter("Peter");
	ClapTrap	john("John");
	ScavTrap	yoyo("Yoyo");
	FlagTrap	flo("Flo");

	flo.highFivesGuys();
	yoyo.attack("John");
	john.takeDamage(yoyo.getattack());
	peter.attack("John");
	john.takeDamage(1);
	john.beRepaired(2);
	john.attack("Peter");
	peter.takeDamage(11);
	peter.beRepaired(5);
	return (0);
}
