#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>
# include <iostream>

class ScavTrap : public ClapTrap // inherit from Claptrap
{
public://need to write constructors and destructor 
    ScavTrap();
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& other);
    ~ScavTrap();

	void	atta
};

ScavTrap::ScavTrap(/* args */)
{
}

ScavTrap::~ScavTrap()
{
}

#endif