#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat : default constructor called" << std::endl;
	brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat : copy constructor called" << std::endl;
	brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete	brain;
		brain = new Brain(*other.brain);
	}
	std::cout << "Cat : copy assignment called" << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat : destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << type << " makes sound : Miaowu!" << std::endl;
}

Brain*	Cat::getBrain() const
{
	return brain;
}
