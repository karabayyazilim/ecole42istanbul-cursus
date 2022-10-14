#include "Zombie.h"

void Zombie::randomChump(string name) {
	Zombie *zombie = new Zombie(name);
	zombie->announce();
	delete zombie;
}