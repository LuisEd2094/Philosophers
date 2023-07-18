#include <stdio.h>
#include <stdlib.h>
#include "philo.h"


int main(int argc, char *argv[])
{
    //t_prg prg;
    remove_white_space_arguments(argv);
    check_arguments(argc, argv);

    printf("VALID ARGUMENTS\n");
    exit(0);    
}