#include "Zombie.h"

Zombie *Zombie::newZombie(string name) {
	return new Zombie(name);
}