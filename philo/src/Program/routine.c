#include <philo.h>

void check_if_odd_philo_to_sleep(t_philo *philo)
{
    if (philo->id % 2 != 0)
    {            
        print_philo_state(IS_THINKING, philo);
        if (philo->prg->eat_time < philo->prg->death_time)
            usleep(philo->prg->eat_time / 2);
        else
            usleep(philo->prg->death_time);
    }    
}

void    execute_routine(t_philo *philo)
{
    take_forks(philo);
    if (check_conditions_continue_thread(philo))
        eat(philo);
    drop_forks(philo);
    if (check_conditions_continue_thread(philo))
        philo_sleep(philo);
}


void	*routine(void *philo_p)
{
    t_philo *philo;

    philo = (t_philo *)philo_p;
    update_num_threads(philo->prg, 1);
    while (1)
    {
        pthread_mutex_lock(&(philo->prg->lock));
        if (philo->prg->can_start)
        {
            pthread_mutex_unlock(&(philo->prg->lock));
            break;
        }
        pthread_mutex_unlock(&(philo->prg->lock));

    }
    philo->time_to_die = philo->prg->start_time + \
                        (philo->prg->death_time / 1000);
    if (!create_thread(&(philo->t1), &supervisor, (void *)philo))
    {
        update_num_threads(philo->prg, -1);
        return (NULL);
    }
    pthread_detach(philo->t1);
    check_if_odd_philo_to_sleep(philo);
    while (check_conditions_continue_thread(philo))
        execute_routine(philo);
    update_num_threads(philo->prg, -1);
    return (NULL);
}