#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
	this->hit = 100;
	this->energy = 100;
	this->attack_point = 30;

	std::cout << "FragTrap " << name << " has been created." << std::endl;
}

FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other.name)
{
}

FragTrap &FragTrap::operator=(FragTrap const &other)
{
	if (this != &other)
	{
		name = other.name;
		hit = other.hit;
		energy = other.energy;
		attack_point = other.attack_point;
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->name << " has died" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (hit <= 0)
	{
		std::cout << "Cannot call Fragtrap because he is dead" << std::endl;
		return;
	}
	std::cout << "I'm a FragTrap please high five me as much as you like" << std::endl;
	std::cout << "Select total high fives: ";
	std::cin >> high; 
	if (std::cin.eof())
	{
		std::cout << "Control D signal received quitting program" << std::endl;
		exit(0);
	}
	if (high <= 0)
	{
		std::cout << "That is an invalid amount of high fives" << std::endl;	
		return ;
	}
	std::cout << "Thank you for the " << this->high << " high five(s)" << std::endl; 
}
