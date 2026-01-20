#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name")
{
	_Name = "Default";
	_HitPoints = FragTrap::_HitPoints;
	_EnergyPoints = ScavTrap::_EnergyPoints;
	_AttackDamage = FragTrap::_AttackDamage;

	std::cout << "DiamondTrap : default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string Name) : ClapTrap(Name + "_clap_name")
{
	_Name = Name;
	_HitPoints = FragTrap::_HitPoints;
	_EnergyPoints = ScavTrap::_EnergyPoints;
	_AttackDamage = FragTrap::_AttackDamage;

	std::cout << "DiamondTrap : parameterized constructor called" << std::endl;
}
//The initializer list runs before the constructor body;
//In a copy constructor, all direct base classes must be explicitly initialized in the initializer list if they do not have a trivial default copy constructor.
DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other),FragTrap(other)
{
	//*this = other; fault
	_Name = other._Name;
	std::cout << "DiamondTrap : copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap : copy assignment called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_Name = other._Name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap : destructor called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _Name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_Name << std::endl;
}