#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

# include "AMateria.hpp"

class ICharacter
{
protected:
	std::string name;
	AMateria* materias[4];
public:
	virtual ~ICharacter() {};
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

// Interfaces (pure abstract classes) usually only have .hpp files.
// Concrete classes have both .hpp and .cpp.

#endif