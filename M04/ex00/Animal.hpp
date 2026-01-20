#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(std::string _type);
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal();// Very important

	std::string getType() const;//the const at the end of function: this function is not allowed to modify the object.

	virtual void  makeSound() const;
};

#endif
