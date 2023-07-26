#include <philo.h>

void    one_philo_case(t_prg *prg)
{
    prg->start_time = get_time(prg);
    prg->f_test = &routine;
    if (!create_thread(&(prg->tid[0]), &(routine), &(prg->philos[0])))
        close_prg(prg);
    pthread_detach(prg->tid[0]);
    while(check_conditions_continue_thread(prg))
    {
        //printf("I AM IN ONE PHILE\n");
        usleep(0);

    }
    close_prg(prg); 
}