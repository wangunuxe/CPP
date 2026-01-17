/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:05:28 by jili              #+#    #+#             */
/*   Updated: 2026/01/17 12:05:33 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << "===== TEST 1: Stack zombie =====" << std::endl;
	randomChump("StackZombie");

	std::cout << std::endl;
	std::cout << "===== TEST 2: Heap zombie =====" << std::endl;
	Zombie* z = newZombie("HeapZombie");
	z->announce();
	delete z;//delete is the C++ keyword used to free memory allocated on the heap with new.

	std::cout << std::endl;
	std::cout << "===== TEST 3: Mixed lifetime =====" << std::endl;
	randomChump("TemporaryZombie");

	Zombie* persistentZombie = newZombie("PersistentZombie");
	persistentZombie->announce();
	delete persistentZombie;

	std::cout << std::endl;
	std::cout << "===== TEST 4: Multiple heap zombies =====" << std::endl;
	Zombie* z1 = newZombie("ZombieA");
	Zombie* z2 = newZombie("ZombieB");

	z1->announce();
	z2->announce();

	delete z1;
	delete z2;

	std::cout << std::endl;
	std::cout << "===== END OF TESTS =====" << std::endl;

	return 0;
}
