#include "Harl.h"

int main(int ac, char** av)
{
    if(ac == 2){
        Harl harl;
        harl.complain(av[1]);
    }
}