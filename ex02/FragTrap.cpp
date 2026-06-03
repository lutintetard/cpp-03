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
	*this = other;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->name << " has died" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
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
