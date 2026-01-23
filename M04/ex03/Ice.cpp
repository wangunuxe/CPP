#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice : default constructor called" << std::endl;	
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	std::cout << "Ice : copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	std::cout << "Ice : copy assignment called" << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice : destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
	AMateria* tmp;
	tmp = new Ice(*this);
	return tmp;
}

void	Ice::use(ICharacter& target)
{
	std::cout << this->getType() << ": * shoots an ice bolt at " << target.getName();
}