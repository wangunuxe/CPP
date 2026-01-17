/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:09:37 by jili              #+#    #+#             */
/*   Updated: 2026/01/17 12:09:39 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA 
{
private:
	std::string name;
	Weapon& weapon;
public:
	HumanA(const std::string& name, Weapon& weapon);
	~HumanA();
	void attack() const;
};

#endif
