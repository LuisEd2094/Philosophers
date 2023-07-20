#include <stdio.h>
#include <stdlib.h>
#include "philo.h"


int main(int argc, char *argv[])
{
    t_prg prg;

    parse_arguments(argc, argv);
    init(&prg, argv, argc);

    printf("VALID ARGUMENTS\n");
    exit(0);    
}