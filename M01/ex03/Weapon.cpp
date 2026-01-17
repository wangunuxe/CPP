/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:10:15 by jili              #+#    #+#             */
/*   Updated: 2026/01/17 12:10:18 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
