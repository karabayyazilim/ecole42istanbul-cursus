#include "Convert.h"

//using namespace std;


int main(int ac,char **av)
{
	if (ac != 2)
	{
		cout << "Usage: ./convert [value]" << endl;
		return 0;
	}
	Convert convert;
	convert.run(av[1]);
}