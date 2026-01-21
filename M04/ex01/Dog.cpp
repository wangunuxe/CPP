#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog : default constructor called" << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog : copy constructor called" << std::endl;
	brain = new Brain(*other.brain);
	// === "new Brain(...)" ===
		// 1. Allocates raw memory large enough for a object Brain;
		// 2. Get an address (a Brain*)
		// 3. Call the constructor that matches his argument;
		// 4. Return the adress;
	// === "Brain(*other.brain)" ===
		
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Dog : copy assignment called" << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog : destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << type << " makes sound : WangWang!" << std::endl;
}

