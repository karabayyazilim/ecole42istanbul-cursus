#include "Zombie.h"

int main()
{
    Zombie zombie;
    Zombie* zombiePtr;

    zombiePtr = zombie.newZombie("Zombie");
    zombie.announce();
    zombiePtr->announce();

    zombie.randomChump("Zombie2");

    delete zombiePtr;
}