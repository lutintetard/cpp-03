#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string const &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->hit = FragTrap::hit;
	this->energy = ScavTrap::energy;
	this->attack_point = FragTrap::attack_point;
	const_cast<std::string&>(this->name) = name;

	std::cout << "DiamondTrap " << name << " has been created." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other) : DiamondTrap(other.name)
{
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other)
{
	FragTrap::operator=(other);
	this->energy = ScavTrap::energy;
	const_cast<std::string&>(this->name) = other.name;
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->name << " has died" << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << this->name << std::endl;
	std::cout << "My ClapTrap name is " << ClapTrap::name << std::endl;
}
