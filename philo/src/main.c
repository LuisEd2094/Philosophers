#include <stdio.h>
#include <stdlib.h>
#include "philo.h"

int ck_argv_content(char *argv[])
{
    int i;

    i = 0;
    while(argv[i])
    {
        if (!argv[i][0])
            return (0);
        i++;
    }
    return (1);
}



void check_arguments(int argc, char *argv[])
{
    if ((argc != 5 && argc != 6))
        print_err((t_error_code)INVALID_NUMBER);
    if (!ck_argv_content(argv))
        print_err((t_error_code)INVALID_CONTENT);
}


int main(int argc, char *argv[])
{
    check_arguments(argc, argv);
    exit(0);    
}