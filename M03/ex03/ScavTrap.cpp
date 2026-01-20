
#include "ScavTrap.hpp"

//constructors, copy assignment and destructor
ScavTrap::ScavTrap() : ClapTrap("Default")//initialize the base class : telling the compiler to call the ClapTrap constructor with "Default" before constructing ScavTrap
{
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << "ScavTrap : default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << "ScavTrap : parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)//Use the ClapTrap copy constructor to copy the base-class part of other
{
	std::cout << "ScavTrap : copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap : copy assignment called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}
ScavTrap::~ScavTrap()//do not need initialize the destructor of ClapTrap
{
	std::cout << "ScavTrap : destructor called" << std::endl;
}

// overridden attack
void	ScavTrap::attack(const std::string& target)
{
	if (this -> _HitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_Name
					<< " can not attack because it has no hit points left."
					<< std::endl;
		return;
	}
	if (this -> _EnergyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_Name
					<< " can not attack beacuse it has no energy points left."
					<< std::endl;
		return;
	}	
	_EnergyPoints--;
	std::cout << "ScavTrap " << _Name 
	<< " attacks " << target 
	<< ", causing " << _AttackDamage << " points of damage !" << std::endl;
	
}

// new ability
void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _Name << " is now in Gate keeper mode" << std::endl;
}
