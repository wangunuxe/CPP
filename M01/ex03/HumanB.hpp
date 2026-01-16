#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>

class HumanB
{
private:
	std::string name;
	Weapon *weapon;//HumanB may not always have a weapon, it is possible that weapon == NULL
public:
	HumanB(const std::string& name);
	~HumanB();
	void setWeapon(Weapon& weapon);
	void attack() const;
};


#endif