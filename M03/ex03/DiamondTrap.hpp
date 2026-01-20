#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>

class DiamondTrap: public ScavTrap, public FragTrap
{
private:
	std::string _Name;//DiamondTrap's own name
public:
	DiamondTrap();
	DiamondTrap(std::string Name);
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap& operator=(const DiamondTrap& other);
	~DiamondTrap();

	void	whoAmI();
	using	ScavTrap::attack;
};

#endif