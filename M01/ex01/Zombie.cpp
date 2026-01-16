#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie()
{
	std::cout << _name << " is destroyed" << std::endl;
}

void	Zombie::setName(std::string name)
{
	_name = name;
}

void	Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
