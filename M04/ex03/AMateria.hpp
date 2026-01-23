#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
//# include "ICharacter.hpp"
	//avoid circular dependencies:
		// AMateria.hpp refers to ICharacter
		// ICharacter.hpp refers to AMateria
class ICharacter;
// The complier only needs to know that ICharactere is a type name, nothing more; 

class AMateria
{
protected:
	std::string _type;

public:
	AMateria();
	AMateria(std::string const& type);
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);
	virtual ~AMateria();

	std::string const& getType() const;
	// we do not need to define the pure virtual function in the file AMateria.cpp
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif