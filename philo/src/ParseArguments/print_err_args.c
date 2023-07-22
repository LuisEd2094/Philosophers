#include <stdio.h>
#include <stdlib.h>
#include <parse.h>

void    print_err_args(char *err_mssg, int err)
{
    printf("%s", err_mssg);
    exit (err);
}