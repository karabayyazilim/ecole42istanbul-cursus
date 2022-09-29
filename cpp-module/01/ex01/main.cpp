#include "Zombie.h"

int main()
{
    Zombie zombie;
    Zombie* zombies;

    zombie.randomChump("Zombie");

    zombies = zombie.zombieHorde(3, "Zombie");

    for (int i = 0; i < 3; ++i) {
        zombies[i].announce();
    }

    delete[] zombies;
}