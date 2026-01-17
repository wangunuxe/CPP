/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:09:58 by jili              #+#    #+#             */
/*   Updated: 2026/01/17 12:09:59 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name) : name(name), weapon(NULL){}

HumanB::~HumanB(){}
//While HumanA takes the Weapon in its constructor, HumanB does not. So we need a function to setWeapon for HumanB
void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack() const
{
	if (this->weapon)
	{
		std::cout << this->name << " attacks with their "
					<< this->weapon->getType()
					<< std::endl;
	}
}



