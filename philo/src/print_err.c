#include <stdio.h>
#include <stdlib.h>
#include "philo.h"

void    print_err(int err)
{
    if (err == INVALID_NUMBER)
        printf(ARG_ERROR_NUM);
    else if (err == INVALID_CONTENT)
        printf(ARG_ERROR_CONTENT);
    exit (1);
}