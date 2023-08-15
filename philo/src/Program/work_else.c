#include <philo.h>

void    work_else(t_prg *prg)
{
    int         i;
    //pthread_t   t0;

    i = 0;

    prg->can_start = 0;
    while (i < prg->philo_num)
    {
        if (!create_thread(&(prg->tid[i]), &(routine), &(prg->philos[i])))
            close_prg(prg);
        pthread_detach((prg->tid[i]));
        i++;
    }
    prg->can_start = 1;
    prg->start_time = get_time(prg);
    printf("Start Time %lli\n", prg->start_time);
    //while(check_conditions_continue_thread(prg))
      //  usleep(0);
    //close_prg(prg); 
}
