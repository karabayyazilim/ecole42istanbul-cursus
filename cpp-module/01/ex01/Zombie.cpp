#include "Zombie.h"

Zombie::Zombie() : _name("Undefined") {
}

Zombie::Zombie(const string &name) {
    this->_name = name;
}

void Zombie::announce() {
    cout << _name << ": BraiiiiiiinnnzzzZ..." << endl;
}

Zombie *Zombie::newZombie(string name) {
    return new Zombie(name);
}

void Zombie::randomChump(string name) {
    Zombie zombie(name);
    zombie.announce();
}

Zombie *Zombie::zombieHorde(int N, string name) {
    Zombie* zombies = new Zombie[N];
    for (int i = 0; i < N ; ++i) {
        zombies[i].setName(name);
    }
    return zombies;
}

void Zombie::setName(const string &name) {
    this->_name = name;
}

Zombie::~Zombie() {
    cout << _name << " deconsructer called" << endl;
}