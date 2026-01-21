#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	std::cout << "\n=== FragTrap CONSTRUCTION ===" << std::endl;
	FragTrap a("Alpha");
	FragTrap b("Beta");
	FragTrap e;
	
	std::cout << "\n=== ScavTrap CONSTRUCTION ===" << std::endl;
	ScavTrap h("Alpha");
	ScavTrap i("Beta");
	ScavTrap j;

	std::cout << "\n=== FragTrap BASIC ATTACK ===" << std::endl;
	a.attack("Trainging Dummy");
	b.attack("Alpha");
	
	std::cout << "\n=== ScavTrap BASIC ATTACK ===" << std::endl;
	h.attack("Trainging Dummy");
	i.attack("Alpha");

	std::cout << "\n=== FragTrap TAKE DAMMAGE ===" << std::endl;
	a.takeDamage(3);
	b.takeDamage(4);

	std::cout << "\n=== ScavTrap TAKE DAMMAGE ===" << std::endl;
	h.takeDamage(3);
	i.takeDamage(4);

	std::cout << "\n=== FragTrap REPAIR ===" << std::endl;
	a.beRepaired(5);

	std::cout << "\n=== ScavTrap REPAIR ===" << std::endl;
	h.beRepaired(5);

	std::cout << "\n=== FragTrap ENERGY DEPLETION ===" << std::endl;
	for (int i = 0; i < 10; i++)
		a.attack("Wall");

	std::cout << "\n=== ScavTrap ENERGY DEPLETION ===" << std::endl;
	for (int i = 0; i < 10; i++)
		h.attack("Wall");

	std::cout << "\n=== FragTrap ATTACK WITH NO ENERGY ===" << std::endl;
	a.attack("Wall");

	std::cout << "\n=== ScavTrap ATTACK WITH NO ENERGY ===" << std::endl;
	h.attack("Wall");

	std::cout << "\n=== FragTrap COPY CONSTRUCTOR ===" << std::endl;
    FragTrap c(b);
    c.attack("Mirror");

	std::cout << "\n=== ScavTrap COPY CONSTRUCTOR ===" << std::endl;
    ScavTrap f(i);
    f.attack("Mirror");

	std::cout << "\n=== FragTrap ASSIGNMENT OPERATOR ===" << std::endl;
    FragTrap d("Delta");
    d = b;
    d.attack("Copied Target");

	std::cout << "\n=== ScavTrap ASSIGNMENT OPERATOR ===" << std::endl;
    ScavTrap g("Delta");
    g = i;
    g.attack("Copied Target");

	std::cout << "\n=== FragTrap High five ===" << std::endl;
	b.highFivesGuys();

	std::cout << "\n=== ScavTrap Gate Keeper mode ===" << std::endl;
	i.guardGate();	

	std::cout << "\n=== END OF PROGRAM ===" << std::endl;
	return 0;
}