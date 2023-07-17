#include "philo.h"

int ck_argv_content(char *argv[])
{
    int i;

    i = 1;
    while(argv[i])
    {
        if (!argv[i][0] ||!check_if_int(argv[i]))
            return (0);
        i++;
    }
    return (1);
}

void check_arguments(int argc, char *argv[])
{
    if ((argc < 5 || argc > 6))
        print_err(INVALID_NUMBER);
    if (!ck_argv_content(argv))
        print_err(INVALID_CONTENT);
}