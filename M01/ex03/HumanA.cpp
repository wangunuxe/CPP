/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:09:23 by jili              #+#    #+#             */
/*   Updated: 2026/01/17 12:09:25 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon){}

HumanA::~HumanA(){}

void HumanA::attack() const
{
	std::cout << this->name << " attacks with their "
				<< this->weapon.getType()
				<< std::endl;
}
