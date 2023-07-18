#include "philo.h"

void remove_white_space_arguments(char *argv[])
{
    int i;

    i = 1;
    while (argv[i])
    {
        if (check_if_white_right_left(argv[i]))
            remove_white_space(argv[i]);
        i++;
    }
}