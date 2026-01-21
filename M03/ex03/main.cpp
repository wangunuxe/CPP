
#include "DiamondTrap.hpp"
int	main()
{
	std::cout << "\n=== DiamondTrap CONSTRUCTION ===" << std::endl;
	DiamondTrap a("Alpha");
	DiamondTrap b("Beta");
	DiamondTrap e;

	std::cout << "\n=== DiamondTrap BASIC ATTACK ===" << std::endl;
	a.attack("Trainging Dummy");
	b.attack("Alpha");

	std::cout << "\n=== DiamondTrap TAKE DAMMAGE ===" << std::endl;
	a.takeDamage(3);
	b.takeDamage(4);

	std::cout << "\n=== DiamondTrap REPAIR ===" << std::endl;
	a.beRepaired(5);

	std::cout << "\n=== DiamondTrap ENERGY DEPLETION ===" << std::endl;
	for (int i = 0; i < 10; i++)
		a.attack("Wall");

	std::cout << "\n=== DiamondTrap ATTACK WITH NO ENERGY ===" << std::endl;
	a.attack("Wall");

	std::cout << "\n=== DiamondTrap COPY CONSTRUCTOR ===" << std::endl;
    DiamondTrap c(b);
    c.attack("Mirror");

	std::cout << "\n=== DiamondTrap ASSIGNMENT OPERATOR ===" << std::endl;
    DiamondTrap d("Delta");
    d = b;
    d.attack("Copied Target");

	std::cout << "\n=== DiamondTrap whoAmI ===" << std::endl;
	c.whoAmI();

	std::cout << "\n=== DiamondTrap High Five ===" << std::endl;
	c.highFivesGuys();

	std::cout << "\n=== DiamondTrap guard Gate ===" << std::endl;
	c.guardGate();

	std::cout << "\n=== END OF PROGRAM ===" << std::endl;
	return 0;
}