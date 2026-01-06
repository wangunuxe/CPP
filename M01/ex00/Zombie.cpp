# include "Zombie.hpp"
// It defines the Zombie constructor and uses an initializer list to initialize the member variable name with the given argument.

//The initializer list
// Zombie::Zombie
// → constructor that belongs to class Zombie

// (std::string n)
// → parameter given when creating a zombie

// : name(n)
// → initializes the member variable name with n

// {}
// → empty body (nothing else to do)

Zombie::Zombie(std::string n) : name(n){}

Zombie::~Zombie()
{
	std::cout << name << " is destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}