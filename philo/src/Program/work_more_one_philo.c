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
        //usleep(1);
        pthread_detach((prg->tid[i]));
        //printf("%i ID \n", prg->philos[i].id);
        usleep(1);
        i++;
    }
    pthread_mutex_lock(&(prg->lock));
    prg->start_time = get_time(prg);
    prg->can_start = 1;
    pthread_mutex_unlock(&(prg->lock));

    /*i = 0;
    while (i < prg->philo_num)
        pthread_detach((prg->tid[i++]));
*/

}
