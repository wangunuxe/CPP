#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	_Name ="Default";
	_HitPoints = 10;
	_EnergyPoints = 10;
	_AttackDamage = 0;
}

ClapTrap:: ClapTrap(std::string Name)
{
	std::cout << "Parameterized constructor called" << std::endl;
	_Name = Name;
	_HitPoints = 10;
	_EnergyPoints = 10;
	_AttackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment called" << std::endl;
	if (this != &other)
	{
		this->_Name = other._Name;
		this->_HitPoints = other._HitPoints;
		this->_EnergyPoints = other._EnergyPoints;
		this->_AttackDamage = other._AttackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if(this->_HitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_Name
					<< " can not attack because it has no hit points left."
					<< std::endl;
		return;		
	}
	if(this->_EnergyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_Name
					<< " can not attack beacuse it has no energy points left."
					<< std::endl;
		return;		
	}
	this->_EnergyPoints--;
	std::cout << "ClapTrap " << _Name 
	<< " attacks " << target 
	<< ", causing " << _AttackDamage << " points of damage !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this -> _HitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_Name
					<< " can not take more damage beacuse it has no hit points left."
					<< std::endl;
		return;
	}	
	if (amount >= this->_HitPoints)
		this->_HitPoints = 0;
	else
		this->_HitPoints -= amount;
	std::cout << "ClapTrap " << this->_Name
			<< " takes damage, and loses "
			<< amount << " hit points!" << std::endl;
	
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this -> _HitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_Name
					<< " can not be repaired beacuse it has no hit points left."
					<< std::endl;
		return;
	}
	if (this -> _EnergyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_Name
					<< " can not be repaired beacuse it has no energy points left."
					<< std::endl;
		return;
	}
	this->_EnergyPoints--;
	this->_HitPoints += amount;
	std::cout << "ClapTrap " << this->_Name
				<< " is repaired and gains " << amount << " hit points!" << std::endl;
}