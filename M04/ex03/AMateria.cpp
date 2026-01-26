# include "AMateria.hpp"

AMateria::AMateria() : _type("AMateria")
{
	// std::cout << "AMateria : default constructor called" << std::endl;	
}

AMateria::AMateria(std::string const& type) : _type(type)
{
	// std::cout << "AMateria : parameterized constructor called" << std::endl;	
}

AMateria::AMateria(const AMateria& other)
{
	// std::cout << "AMateria : copy constructor called" << std::endl;	
	*this = other;
}
	
AMateria& AMateria::operator=(const AMateria& other)
{
	// std::cout << "AMateria : copy assignment called" << std::endl;	
	if (this != &other)
		this->_type = other._type;
	return *this;
}
AMateria::~AMateria()
{
	// std::cout << "AMateria : destructor called" << std::endl;
}

std::string const& AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	//defaut behavior: do noting;
}


//AMateria defines what a Materia is, MateriaSource creates Materias, and Character uses Materias.Each class has one responsibility.