#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	// std::cout << "MateriaSource : default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_template[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	// std::cout << "MateriaSource : copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other._template[i])
			this->_template[i] = other._template[i]->clone();
		else
			this->_template[i] = NULL;	
	}	
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	// std::cout << "MateriaSource : copy assignment called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete _template[i];
			_template[i] = NULL;
		}//ATTENTION
		for (int i = 0; i < 4; i++)
		{
			if (other._template[i])
				this->_template[i] = other._template[i]->clone();	
		}		
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	// std::cout << "MateriaSource : destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete _template[i];
		_template[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if(_template[i] == NULL)
		{
			_template[i] = m->clone();
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_template[i] && _template[i]->getType() == type)
			return _template[i]->clone();
	}
	return NULL;
}