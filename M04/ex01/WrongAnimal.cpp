#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") 
{
	std::cout << "WrongAnimal : default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string _type) : type(_type)
{
	std::cout << "WrongAnimal : parametrerized constructor called" << std::endl;	
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "WrongAnimal : copy constructor called" << std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "WrongAnimal : copy assignment called" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal : destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void	 WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makes a generic sound" << std::endl;
}

