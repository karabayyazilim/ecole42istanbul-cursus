#include <iostream>
#include <time.h>
#include "A.h"
#include "B.h"
#include "C.h"

using std::cout;
using std::endl;

Base * generate(void)
{
	int r = rand() % 3;
	if(r == 0)
		return new A;
	else if(r == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p)
{
	if((A*)dynamic_cast<A*>(p) != NULL)
		cout << "Class ID: A" << endl;
	else if((B*)dynamic_cast<B*>(p) != NULL)
		cout << "Class ID: B" << endl;
	else if((C*)dynamic_cast<C*>(p) != NULL)
		cout << "Class ID: C" << endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		cout << "Class ID Ref: A" << endl;
		return;
	} catch (std::bad_cast) {
	}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Class ID Ref: B" << std::endl;
		return;
	} catch (std::bad_cast) {

	}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Class ID Ref: C" << std::endl;
		return;
	} catch (std::bad_cast) {

	}
}

int main()
{
	srand (time(NULL));

	Base *base = generate();

	identify(base);
	identify(*base);
}