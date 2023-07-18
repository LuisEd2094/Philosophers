#include "philo.h"
#include <stdio.h>

int check_values(int i, char *argv)
{
    int value;

    if (!check_if_int(argv))
        return (NO_INT_VALUE);
    value = ft_atoi(argv);
    if (i == 1 && value > MAX_PHILOS)
        return (INVALID_PHILOS);
    else if ((i >= 2 || i <= 4) && value > MAX_TIME)
        return (INVALID_TIME);
    else if (value <= 0)
        return (INVALID_VALUE);
    return (OK);
}


int ck_argv_content(char *argv[])
{
    int i;
    int err;

    i = 1;
    while(argv[i])
    {
        if (check_if_white_right_left(argv[i]))
            remove_white_space(argv[i]);
        if (!argv[i][0])
            return (INVALID_CONTENT);
        err = check_values(i, argv[i]);
        if (err)
            return (err);
        i++;
    }
    return (OK);
}

void check_arguments(int argc, char *argv[])
{
    int err;

    if ((argc < 5 || argc > 6))
        print_err(INVALID_NUMBER);
    err = ck_argv_content(argv);
    if (err)
        print_err(err);
}