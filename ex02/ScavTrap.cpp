#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
	this->hit = 100;
	this->energy = 50;
	this->attack_point = 20;
	this->guard = false;

	std::cout << "ScavTrap " << name << " has been created." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other.name)
{
	this->guard = other.guard;	
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
	if (this != &other)
	{
		name = other.name;
		energy = other.energy;
		attack_point = other.attack_point;
		guard = other.guard;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->name << " has died" << std::endl;
}

void ScavTrap::attack(std::string const &name)
{
	if (hit <= 0)
	{
		std::cout << "ScavTrap " << this->name << " is dead" << std::endl;
		return ;
	}
	if (energy <= 0)
	{
		std::cout << "ScavTrap " << this->name << " is tired and can't be bothered to attack" << std::endl;
		return ;
	}	
	if (this->guard == true)
	{
		std::cout << "ScavTrap " << this->name << " is guarding the gate and cannot attack" << std::endl;
		return ; 
	}
	std::cout << "I'm a ScavTrap (" << this->name << ") so I attack differently" << std::endl;
	std::cout << name << " gets absolutely smashed" << std::endl;
	energy--;
	return ;	
}

void	ScavTrap::guardGate(void)
{

	if (this->guard == false)
	{
		std::cout << this->name << " will start guarding the gate" << std::endl;
		this->guard = true;
		return;
	}
	if (this->guard == true)
	{
		std::cout << this->name << " will no longer guard the gate" << std::endl;
		this->guard = false;
		return;
	}
}
