/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:07:40 by jili              #+#    #+#             */
/*   Updated: 2026/01/17 12:07:43 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
//delete z; is used to free ONE object created with new, while delete[] horde; is used to free MANY objects created with new[].
int main()
{
	int N = 5;

	std::cout << "Creating a horde of " << N << " zombies\n";
	Zombie* horde = zombieHorde(N, "HordeZombie");
	if (!horde)
	{
		std::cout << "zombieHorde failed\n";
		return 1;
	}

	std::cout << "\nAnnouncing all zombies:\n";
	for (int i = 0; i < N; ++i)
		horde[i].announce();
	
	std::cout << "\nDeleting zombie horde\n";
	delete[] horde;

	return 0;
}
