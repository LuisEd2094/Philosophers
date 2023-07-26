#include <philo.h>

void    work_else(t_prg *prg)
{
    int         i;
    //pthread_t   t0;

    i = 0;
    prg->start_time = get_time(prg);
    printf("%i\n", prg->philo_num);
    while (i < prg->philo_num)
    {
        if (!create_thread(&(prg->tid[i]), &(routine), &(prg->philos[i])))
            close_prg(prg);
        i++;
        //pthread_detach(prg->tid[i]);
    }
    while(check_conditions_continue_thread(prg))
        usleep(0);
    close_prg(prg); 
}