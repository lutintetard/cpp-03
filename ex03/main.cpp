#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap	peter("Peter");
	ClapTrap	john("John");
	ScavTrap	yoyo("Yoyo");
	FragTrap	flo("Flo");
	DiamondTrap	clara("Clara");

	//clara.attack("yoyo");
	clara.whoAmI();
		//flo.highFivesGuys();
	//	yoyo.attack("John");
//		john.takeDamage(yoyo.getattack());
//		peter.attack("John");
//		john.takeDamage(1);
//		john.beRepaired(2);
//		john.attack("Peter");
//		peter.takeDamage(11);
//		peter.beRepaired(5);
	return (0);
}
