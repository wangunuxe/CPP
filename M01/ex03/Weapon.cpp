#include "Weapon.hpp"
Weapon::Weapon(){};

Weapon::~Weapon(){};

Weapon::Weapon(const std::string& type)
{
	this->type = type;
}
const std::string& Weapon::getType() const
{
	return this->type;
}

void Weapon::setType(const std::string& type)
{
	this->type = type;
}