#include "A_Animal.hpp"

Animal::Animal() : type("Animal") 
{
	std::cout << "Animal : default constructor called" << std::endl;
}

Animal::Animal(std::string _type) : type(_type)
{
	std::cout << "Animal : parametrerized constructor called" << std::endl;	
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal : copy constructor called" << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "Animal : copy assignment called" << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal : destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}

void	 Animal::makeSound() const
{
	std::cout << "Animal makes a generic sound" << std::endl;
}

