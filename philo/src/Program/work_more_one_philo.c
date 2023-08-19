#include <philo.h>

void    work_more_one_philo(t_prg *prg)
{
    int i;

    i = 0;
    prg->can_start = 0;
    while (i < prg->philo_num)
    {
        if (!create_thread(&(prg->tid[i]), &(routine), &(prg->philos[i])))
            close_prg(prg);
        pthread_detach((prg->tid[i]));
        i++;
    }
    prg->start_time = get_time(prg);
    prg->can_start = 1;
}
