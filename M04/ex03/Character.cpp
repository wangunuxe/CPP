#include "Character.hpp"

Character::Character() : _name("Default") 
{
	// std::cout << "Character : default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}
Character::Character(const std::string& name) : _name(name)
{
	// std::cout << "Character : Parameterized constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

//deep copy
Character::Character(const Character& other) : _name(other._name)
{
	// std::cout << "Character : copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if(other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}


Character& Character::operator=(const Character& other)
{
	// std::cout << "Character : copy assignment called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;

		//delete current inventory
		for(int i = 0; i < 4; i++)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
		//deep copy from other
		for(int i = 0; i < 4; i++)
		{
			if(other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();// clone() use the "new"	
		}
	}
	return *this;
}
//Requirement of subject: "Of course, the Materias must be deleted when a Character is destroyed.
Character::~Character()
{
	// std::cout << "Character : destructor called" << std::endl;
	for(int i = 0; i < 4; i++)
	{
		delete _inventory[i];
		_inventory[i] = NULL;
	}
}

std::string const& Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return; // test the parameter
	for(int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return;// test the parameter
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
		return;
	if (_inventory[idx])
		_inventory[idx]->use(target);
}