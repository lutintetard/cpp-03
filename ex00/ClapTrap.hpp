#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
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
private:
	int	hit;
	int	energy;
	int	attack_point;
	std::string	const name;
};

#endif
