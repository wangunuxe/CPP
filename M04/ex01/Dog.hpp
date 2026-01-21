#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>
# include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* brain;
public:
	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	virtual ~Dog();

	virtual void makeSound() const;

	//for tests
	Brain* getBrain() const;
};

#endif