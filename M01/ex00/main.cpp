#include "Zombie.hpp"

int main()
{
	randomChump("StackZombie");

	Zombie* z = newZombie("HeapZombie");
	z->announce();
	delete z;//delete is the C++ keyword used to free memory allocated on the heap with new.

	return 0;

}