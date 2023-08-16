#include <philo.h>

void    one_philo_case(t_prg *prg)
{
    prg->start_time = get_time(prg);
    if (!create_thread(&(prg->tid[0]), &(routine), &(prg->philos[0])))
        close_prg(prg);
    pthread_detach(prg->tid[0]);
    prg->can_start = 1;
    while(check_conditions_continue_thread(&(prg->philos[0])))
        usleep(0);
    close_prg(prg); 
}
