#include <philo.h>


void    handle_death_of_philo(t_philo *philo, uint64_t time)
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
}


bool check_if_super_continue(t_philo *philo)
{
    if (!(philo->prg->dead) && !(philo->prg->err) \
        && (philo->prg->finished != philo->prg->philo_num))
        return(1);
    return (0);
}

bool chk_phi_done_meals(t_philo *philo)
{
    if (philo->prg->meals_nb < 0)
        return (0);
    if (philo->prg->finished == philo->prg->philo_num )
        return (1);
    return (0);
}

void    *supervisor(void *philo_p)
{
    t_philo *philo;
    uint64_t time;

    philo = (t_philo *)philo_p;
    update_num_threads(philo->prg, 1);
    while (check_if_super_continue(philo) && !chk_phi_done_meals(philo))
    {
        //usleep(philo->prg->sleep_time / 2);
        pthread_mutex_lock(&(philo->lock));
        time = get_time(philo->prg);
        if ((time >= philo->time_to_die))
        {
            handle_death_of_philo(philo, time);
            pthread_mutex_unlock(&philo->lock);
            break ;
        }
        pthread_mutex_unlock(&philo->lock);
    }
    update_num_threads(philo->prg, -1);
    return (NULL);
}