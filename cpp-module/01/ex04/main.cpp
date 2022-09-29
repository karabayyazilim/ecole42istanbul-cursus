#include <iostream>
#include "FileReplacer.h"

int main(int ac, char** av)
{
    if(ac == 4)
    {
        FileReplacer fileReplacer(av[1]);
        fileReplacer.replace(av[2],av[3]);
    }
}
