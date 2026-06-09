#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const &name) :
	name(name),
	hit(10),
	energy(10),
	attack_point(0)
{
	std::cout << "ClapTrap " << name << " was created " << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other) :
	name(other.getname()),
	hit(other.gethit()),
	energy(other.getenergy()),
	attack_point(other.getattack())
{
	std::cout << "copy created" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	if (this != &other)
	{
		name = other.getname();
		hit = other.hit;
		energy = other.energy;
		attack_point = other.attack_point;	
	} 
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << name << " died" << std::endl;
}

std::string	ClapTrap::getname(void) const
{
	return (name);
}

int	ClapTrap::gethit(void) const
{
	return (hit);
}

int	ClapTrap::getenergy(void) const
{
	return (energy);
}

int	ClapTrap::getattack(void) const
{
	return (attack_point);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hit <= 0)
	{
		std::cout << "This ClapTrap is dead (HP <= 0)" << std::endl;
		return ;
	}
	else if (this->energy <= 0)
	{
		std::cout << "ClapTrap " << getname() << " cannot attack because it has no energy"
			<< std::endl;	
		return ;
	}
	std::cout << "ClapTrap " << getname() << " attacks " << target << ", causing " <<
attack_point << " points of damage !" << std::endl;
	energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit <= 0)
	{
		std::cout << "ClapTrap " << name  << " had already died" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " has taken " << amount << " damage" << std::endl;
	hit -= amount;
	if (hit <= 0)
	{
		std::cout << "ClapTrap " << name << " has died" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy <= 0)
	{
		std::cout << "ClapTrap " << getname() << " cannot attack because it has no energy"
			<< std::endl;	
		return ;
	}
	else if (hit <= 0)
	{
		std::cout << "ClapTrap " << name << " has already died and cannot be healed" << std::endl;
		return ;
	}
	hit += amount;
	std::cout << "ClapTrap " << name << " has healed and now has " << hit << " live points" << std::endl;
	energy--;
}
