#include <philo.h>
#include <stdio.h>

void    print_err_prg(char *err, t_prg *prg)
{
    printf("%s", err);
    close_prg(prg);
}