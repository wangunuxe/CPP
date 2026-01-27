#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"

int main()
{
	{
		std::cout << "===== TEST 1 =====" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;

	}

	// {
	// 	std::cout << "\n===== TEST 2 : Unknown Materia type =====" << std::endl;
	// 	IMateriaSource* src1 = new MateriaSource();
	// 	src1->learnMateria(new Ice());

	// 	AMateria* tmp1 = src1->createMateria("fire");

	// 	if (!tmp1)
	// 		std::cout << "Unknown materia correctly returns NULL" << std::endl;

	// 	delete src1;
	// }

	// {
	// 	std::cout << "\n===== TEST 3 : Inventory limit (max 4 Materias) =====" << std::endl;

	// 	IMateriaSource* src2 = new MateriaSource();
	// 	src2->learnMateria(new Ice());

	// 	Character me2("me2");
	// 	for (int i = 0; i < 6; i++)
	// 	{
	// 		AMateria* tmp2 = src->createMateria("ice");// for iteration 4 and 5,createMateria → new Ice AND equip(tmp) → does NOTHING(we have not given these two pointers to Character me2, so these two tmp2 pointers is still owned by main → must delete)
	// 		if (tmp2)
	// 		{
	// 			me2.equip(tmp);
	// 			if (i >= 4)
	// 				delete tmp2;
	// 		}
	// 	}
	// 	Character bob2("bob");
	// 	for (int i = 0; i < 6; i++)
	// 		me2.use(i, bob2);
	// 	delete src2;
	// }

	// {
	// 	std::cout << "\n===== TEST 4 : Unequip does NOT delete object =====" << std::endl;
	// 	IMateriaSource* src3 = new MateriaSource();
	// 	src3->learnMateria(new Cure());

	// 	Character me3("me3");
	// 	Character bob3("bob3");

	// 	AMateria* tmp3 = src->createMateria("cure");
	// 	me3.equip(tmp3);
	// 	me3.unequip(0);

	// 	tmp3->use(bob3);
	// 	delete tmp3;
	// 	delete src3;
	// }
	// {
	// 	std::cout << "\n===== TEST 5 : Deep copy of Character (copy constructor) =====" << std::endl;
	// 	IMateriaSource* src = new MateriaSource();
	// 	src->learnMateria(new Ice());
	// 	src->learnMateria(new Cure());

	// 	Character original("original");
	// 	original.equip(src->createMateria("ice"));

	// 	Character copy(original);

	// 	Character bob("bob");
	// 	std::cout << "\n              ===== First output of TEST 5  =====" << std::endl;
	// 	original.use(0, bob);
	// 	copy.use(0, bob);

	// 	original.unequip(0);
	// 	original.equip(src->createMateria("cure"));
	// 	std::cout << "\n              ===== Second output of TEST 5  =====" << std::endl;
	// 	original.use(0, bob);
	// 	copy.use(0, bob);
	// 	delete src;
	// }
	return 0;
}
