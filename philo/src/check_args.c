#include "philo.h"
#include <stdio.h>

int check_values(int i, char *argv)
{
    if (i == 1 && ft_atoi(argv) > MAX_PHILOS)
        return (INVALID_PHILOS);
    else if ((i >= 2 || i <= 4) && ft_atoi(argv) > MAX_TIME)
        return (INVALID_TIME);
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
        if (!argv[i][0] || !check_if_int(argv[i]) || \
        get_sign(argv[i]) == -1 || ft_atoi(argv[i]) == 0)
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