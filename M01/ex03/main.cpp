/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:10:39 by jili              #+#    #+#             */
/*   Updated: 2026/01/17 12:10:47 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	{
		Weapon club("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();

		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();

		club.setType("some other type of club");
		jim.attack();
	}

	return 0;
}
