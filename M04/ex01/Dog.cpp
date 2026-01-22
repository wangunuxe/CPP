#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog : default constructor called" << std::endl;
	brain = new Brain();
}

//deep copy
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
		// Use the constructor of Brain that matchses this argument "*other.brain"
	// === *other.Brain ===
		// 1. "other" is an object of Dog
		// 2. "other.brain" is an adress of Brain, because it's type is "Brain*"
		// 3. "*other.brain" is the object itself, and it's type is "Brain"
	// === Call the copy constructor : Brain(const Brain& other)
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);//copy base part
		delete brain; //clean the old resource of "this"
		brain = new Brain(*other.brain);
	}
	std::cout << "Dog : copy assignment called" << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog : destructor called" << std::endl;
	delete brain; //delete the brain before deleting the Dog;
}

void	Dog::makeSound() const
{
	std::cout << type << " makes sound : WangWang!" << std::endl;
}

Brain* Dog::getBrain() const
{
	return brain;
}

