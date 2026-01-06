#include "Zombie.hpp"

Zombie::Zombie() : name(""){}

Zombie::~Zombie()
{
	std::cout << name << " is destroyed" << std::endl;
}

void	Zombie::setName(std::string n)
{
	name = n;
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
