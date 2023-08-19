#include <philo.h>

void    *supervisor(void *philo_p)
{
    t_philo *philo;
    uint64_t time;

    philo = (t_philo *)philo_p;
    update_num_threads(philo->prg, 1);
    while (!(philo->prg->dead) && !(philo->prg->err) && (philo->prg->finished != philo->prg->philo_num))
    {
        usleep(philo->prg->death_time / 100);
        if (philo->prg->meals_nb > 0 && philo->prg->finished == philo->prg->philo_num )// || philo->eat_count == philo->prg->meals_nb)
            break;
        if (philo->prg->meals_nb > 0 && philo->prg->finished == philo->prg->philo_num )// || philo->eat_count == philo->prg->meals_nb)
            break;
        time = get_time(philo->prg);
        pthread_mutex_lock(&(philo->lock));
        if ((time >= philo->time_to_die))
        {
            pthread_mutex_lock(&(philo->prg->lock));
            if (philo->prg->dead == 0)
            {
                printf("%lu %d %s\n", time - (philo->prg->start_time), \
                philo->id, DIED);   
                philo->prg->dead = 1;
            }
            pthread_mutex_unlock(&(philo->prg->lock));
            philo->can_continue = 0;
            pthread_mutex_unlock(&philo->lock);
            break ;
        }
        pthread_mutex_unlock(&philo->lock);
    }
    update_num_threads(philo->prg, -1);
    return (NULL);
}