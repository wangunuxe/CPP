#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "===== Creating Animal array =====" << std::endl;
	const int size = 10;
	Animal* animals[size];
	for (int i = 0; i < size / 2; i++)
		animals[i] = new Cat();

	for (int i = size /2; i < 10; i++)
		animals[i] = new Dog();
	for (int i = 0; i < size; i++)
	{
		std::cout << "Animal[" << i << "] is type: " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}
	std::cout << "\n===== deleting Animal array =====" << std::endl;
	for (int i = 0; i < size; i++)
		delete animals[i];

	std::cout << "\n===== testing deep copy =====" << std::endl;
	Dog original;
	original.getBrain()->setIdea(0, "I am a good dog");
	Dog copy = original;

	std::cout << "\n      ===== first output =====      " << std::endl;
	std::cout << "The idea of the original dog: " << original.getBrain()->getIdea(0) << std::endl;
	std::cout << "The idea of the copy dog: " << copy.getBrain()->getIdea(0) << std::endl;

	std::cout << "\n      ===== second output =====      " << std::endl;
	original.getBrain()->setIdea(0, "I am a cute dog");	
	std::cout << "The idea of the original dog: " << original.getBrain()->getIdea(0) << std::endl;
	std::cout << "The idea of the copy dog: " << copy.getBrain()->getIdea(0) << std::endl;

	std::cout << "\n===== testing deep copy for the lifetime of copy_object =====" << std::endl;

	Dog original_1;
	original_1.getBrain()->setIdea(0, "I am a good good dog");
	{
		std::cout << "\n      ===== in the scope =====      " << std::endl;	
		Dog copy_1 = original_1;
		std::cout << "The idea of the original_1 dog: " << original_1.getBrain()->getIdea(0) << std::endl;
		std::cout << "The idea of the copy_1 dog: " << copy_1.getBrain()->getIdea(0) << std::endl;
	}
	std::cout << "\n      ===== outside of the scope =====      " << std::endl;
	std::cout << "The idea of the original_1 dog: " << original_1.getBrain()->getIdea(0) << std::endl;
	//std::cout << "The idea of the copy_1 dog: " << copy_1.getBrain()->getIdea(0) << std::endl;

	std::cout << "\n===== end of programme =====" << std::endl;
	return 0;
}
