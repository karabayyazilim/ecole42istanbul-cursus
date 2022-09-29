#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Zombie
{
public:
    Zombie();
    Zombie(const string& name);

    void announce();
    Zombie* newZombie(string name);
    void randomChump(string name);
    Zombie* zombieHorde(int N, string name);
    void setName(const string& name);

    ~Zombie();

private:
    string _name;
};


#endif
