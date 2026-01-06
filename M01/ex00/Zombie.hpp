#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>
# include <iostream>

class	Zombie
{
private:
	std::string name;
public:
	Zombie(std::string n);// The declaration of constructor is necessary, beacuse the name of a Zombie should not be a empty
	~Zombie();
	void announce(void);
};

void	randomChump(std::string name);
Zombie* newZombie(std::string name);
#endif
