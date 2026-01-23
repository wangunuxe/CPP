#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria* _inventory[4];
	//Why: array of pointers, the type of element is AMateria*
	//R1: "The unequip() member function must NOT delete the Materia"
		//array of pointers: removing a Materia != destroying it
		//BUT: array of object: AMateria _inventory[4]
			// 1. In C++, objects stored by value have their lifetime contralled by the scope/container that holds them; The array of objects "_inventory" is the container of the 4 objectm, that means the array creates the 4 objects, destroys the 4 objects; And the objects cannot exist independently of the array;
			// 2. When I write : AMateria _inventory[4], the compiler will:
				//First, Allocate memory for 4 objects of type AMaterai;
				//second, construct each object by calling automatically the default constructor;
				//So the objects cannot be "empty", and we can not make an object "not exist"
	//R2: AMateria can not be instantiated, so AMateria _inventory[4] is not correct;
	public:
	Character();
	Character(const std::string& name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	virtual ~Character() {};

	//ICharacher interface
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};


#endif