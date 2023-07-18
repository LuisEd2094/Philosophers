#include <stdio.h>
#include <stdlib.h>
#include "philo.h"


void init_prg(t_prg *prg)
{
    prg->test = 1;
    prg->str = "HOLA";
}


int main(int argc, char *argv[])
{
    t_prg prg;

    check_arguments(argc, argv);
    init_prg(&prg);
    printf("TEST %i STR %s \n", prg.test, prg.str);
    printf("VALID ARGUMENTS\n");
    exit(0);    
}