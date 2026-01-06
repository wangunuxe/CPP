#include "Zombie.hpp"
//newZombie allocates a Zombie on the heap using new, initializes it with the given name, and returns a pointer to it.
Zombie*	newZombie(std::string name)
{
	Zombie *z = new Zombie(name);
	return z;
}