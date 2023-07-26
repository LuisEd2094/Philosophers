#include <philo.h>

void    *supervisor(void *philo_p)
{
    t_philo *philo;

    philo = (t_philo *)philo_p;
    update_num_threads(philo->prg, 1);
    while (!(philo->prg->dead) && !(philo->prg->err))
    {
        pthread_mutex_lock(&(philo->lock));
        if ((get_time(philo->prg) >= philo->time_to_die))
        {
            pthread_mutex_lock(&(philo->prg->lock));
            philo->prg->dead = 1;
            print_philo_state(DIED, philo);
            pthread_mutex_unlock(&(philo->prg->lock));
        }
        if (philo->eat_count == philo->prg->meals_nb)
        {
            pthread_mutex_lock(&(philo->prg->lock));
            philo->prg->finished++;
            pthread_mutex_unlock(&(philo->prg->lock));
        }
        pthread_mutex_unlock(&philo->lock);
    }
    update_num_threads(philo->prg, -1);
    return (NULL);
}


void	*routine(void *philo_p)
{
    t_philo *philo;

    philo = (t_philo *)philo_p;
    update_num_threads(philo->prg, 1);
    while (!philo->prg->can_start)
        usleep(0);
    //printf("time to die%li current time%li death time %li", philo->prg->death_time, get_time(philo->prg), philo->time_to_die);
    philo->time_to_die = philo->prg->death_time + get_time(philo->prg);
    //printf("time to die %li current time %li death time %li\n", philo->prg->death_time, get_time(philo->prg), philo->time_to_die);
    if (!create_thread(&(philo->t1), &supervisor, (void *)philo))
    {
        update_num_threads(philo->prg, -1);
        return (NULL);
    }
    pthread_detach(philo->t1);
    while ((check_conditions_continue_thread(philo->prg)))
    {
        if (!take_forks(philo))
            break ;
        eat(philo);
        drop_forks(philo);
        philo_sleep(philo);
        print_philo_state(IS_THINKING, philo);
    }
    update_num_threads(philo->prg, -1);
    return (NULL);
}