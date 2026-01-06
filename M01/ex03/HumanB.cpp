#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name)
    : name(name), weapon(NULL)
{
}

//
void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;//This line stores the address of an existing Weapon object inside the HumanB object. Take the address of an external Weapon reference and store it in a Weapon* pointer.
}

void HumanB::attack() const
{
    if (weapon)
    {
        std::cout << name << " attacks with their "
                  << weapon->getType()
                  << std::endl;
    }
}



