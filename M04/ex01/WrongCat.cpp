#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat : default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat : copy constructor called" << std::endl;	
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
	std::cout << "WrongCat : copy assignment called" << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat : destructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << type << " makes sound : Miaowu!" << std::endl;
}
