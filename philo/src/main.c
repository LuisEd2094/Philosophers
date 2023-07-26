#include <stdlib.h>
#include <philo.h>

int main(int argc, char *argv[])
{
    t_prg prg;

    parse_arguments(argc, argv);
    init(&prg, argv, argc);
    if (prg.philo_num == 1)
        one_philo_case(&prg);
    else
        work_else(&prg);
    printf("VALID ARGUMENTS\n");
    close_prg(&prg);    
}