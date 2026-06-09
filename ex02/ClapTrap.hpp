#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
protected:
	std::string	 name;
	int	hit;
	int	energy;
	int	attack_point;
public:
	ClapTrap(std::string const &name);
	ClapTrap(ClapTrap const &other);
	~ClapTrap(void);
	ClapTrap &operator=(ClapTrap const &other); 
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string	getname(void) const;
	int	gethit(void) const;
	int	getenergy(void) const;
	int	getattack(void) const;
};

#endif
