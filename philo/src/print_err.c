#include <stdio.h>
#include <stdlib.h>
#include "philo.h"

void    print_err(int err)
{
    if (err == INVALID_NUMBER)
        printf(ARG_ERROR_NUM);
    else if (err == INVALID_CONTENT)
        printf(ARG_ERROR_CONTENT);
    else if (err == INVALID_PHILOS)
        printf(ARG_INVALID_PHILOS);
    else if (err == INVALID_TIME)
        printf(ARG_INVALID_TIME);
    else if (err == INVALID_VALUE)
        printf(ARG_ZERO_VALUE);
    else if (err == NO_INT_VALUE)
        printf(ARG_INT_VALUE);
    exit (1);
}