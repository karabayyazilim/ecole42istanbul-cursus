#include "Dog.h"
#include "Cat.h"
#include "WrongCat.h"

int main()
{
	//const Animal *animal = new Animal();

	const Animal* animal[6] = {
			new Dog(),
			new Cat(),
			new Dog(),
			new Cat(),
			new Dog(),
			new Cat()
	};

	for (int i = 0; i < 6; i++) {
		animal[i]->makeSound();
		delete animal[i];
	}

	return 0;
}