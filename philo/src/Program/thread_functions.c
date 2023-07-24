#include <philo.h>

void    update_num_threads(t_prg *prg, int value)
{
    pthread_mutex_lock(&(prg->lock));
    prg->num_threads += value;
    pthread_mutex_unlock(&(prg->lock));
}

void    *supervisor(void *philo_p)
{
    t_philo *philo;

    philo = (t_philo *)philo_p;
    update_num_threads(philo->prg, 1);
    while (!philo->prg->dead)
    {
        pthread_mutex_lock(&philo->lock);
        if ((get_time(philo->prg) >= philo->time_to_die))
        {
            pthread_mutex_lock(&philo->prg->lock);
            philo->prg->dead = 1;
            print_philo_state(DIED, philo);
            pthread_mutex_unlock(&philo->prg->lock);
        }
        if (philo->eat_count == philo->prg->meals_nb)
        {
            pthread_mutex_lock(&philo->prg->lock);
            philo->prg->finished++;
            philo->eat_count++;
            pthread_mutex_unlock(&philo->prg->lock);
        }
        pthread_mutex_unlock(&philo->lock);
    }
    update_num_threads(philo->prg, -1);
    return ((void *)0);
}


void	*routine(void *philo_p)
{
    t_philo *philo;

    philo = (t_philo *)philo_p;
    update_num_threads(philo->prg, 1);
    philo->time_to_die = philo->prg->death_time + get_time(philo->prg);
    if (pthread_create(&(philo->t1), NULL, &supervisor, (void *)philo))
        print_err_prg("ERROR\n", (philo->prg));
    pthread_detach(philo->t1);
    while (!philo->prg->dead)
    {
        if (!take_forks(philo))
            break ;
        printf("I am inside lopp, Philo\n");
        eat(philo);
        drop_forks(philo);
        print_philo_state(IS_THINKING, philo);
    }
    update_num_threads(philo->prg, -1);
    return ((void *) 0);
}