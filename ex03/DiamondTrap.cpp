#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string const &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->hit = FragTrap::hit;
	this->energy = ScavTrap::energy;
	this->attack_point = FragTrap::attack_point;
	this->attack = &ScavTrap::attack();

	std::cout << "DiamondTrap " << name << " has been created." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other) : DiamondTrap(other.name)
{
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other)
{
	*this = other;
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->name << " has died" << std::endl;
}


