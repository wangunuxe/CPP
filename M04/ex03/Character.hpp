#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include "AMateria.hpp"

class Character : public ICharacter
{
public:
	virtual ~Character() {}
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};


#endif