#include "ClapTrap.hpp"

int	main()
{
	std::cout << "\n=== CONSTRUCTION ===" << std::endl;
	ClapTrap a("Alpha");
	ClapTrap b("Beta");
	ClapTrap e;

	std::cout << "\n=== BASIC ATTACK ===" << std::endl;
	a.attack("Trainging Dummy");
	b.attack("Alpha");

	std::cout << "\n=== TAKE DAMMAGE ===" << std::endl;
	a.takeDamage(3);
	a.takeDamage(4);

	std::cout << "\n=== REPAIR ===" << std::endl;
	a.beRepaired(5);

	std::cout << "\n=== ENERGY DEPLETION ===" << std::endl;
	for (int i = 0; i < 10; i++)
		a.attack("Wall");

	std::cout << "\n=== ATTACK WITH NO ENERGY ===" << std::endl;
	a.attack("Wall");

	std::cout << "\n=== COPY CONSTRUCTOR ===" << std::endl;
    ClapTrap c(a);
    c.attack("Mirror");

	std::cout << "\n=== ASSIGNMENT OPERATOR ===" << std::endl;
    ClapTrap d("Delta");
    d = b;
    d.attack("Copied Target");

	std::cout << "\n=== END OF PROGRAM ===" << std::endl;
	return 0;
}