#include <stdio.h>
#include <stdlib.h>
#include "philo.h"

void    print_err(int err)
{
    if (err == INVALID_NUMBER)
        printf("Invalid number of arguments. See subject.\n");
    else if (err == INVALID_CONTENT)
        printf("One of your arguments is invalid, \
check subject and try again.\n");
    exit (1);
}