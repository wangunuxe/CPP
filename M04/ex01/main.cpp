#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "===== Animal and Cat =====" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "\n===== WrongAnimal and WrongCat =====" << std::endl;
	const WrongAnimal* beta = new WrongAnimal();
	const WrongAnimal* c = new WrongCat();
	std::cout << c->getType() << " " << std::endl;
	c->makeSound(); 
	beta->makeSound();

	delete beta;
	delete c;

	std::cout << "\n===== more tests =====" << std::endl;

	const Animal* animals[3];
	animals[0] = new Animal();
	animals[1] = new Cat();
	animals[2] = new Dog();

	for (int i = 0; i < 3; i++)
		animals[i]->makeSound();
	for (int i = 0; i < 3; i++)
		delete animals[i];
	std::cout << "\n===== end =====" << std::endl;
	return 0;
}
