#include "Zombie.hpp"
//delete z; is used to free ONE object created with new, while delete[] horde; is used to free MANY objects created with new[].
int main()
{
    Zombie *h = zombieHorde(5, "ZombieH");
    for (int i = 0; i < 5; i++)
        h[i].announce();
    delete[] h;
    return 0;
}