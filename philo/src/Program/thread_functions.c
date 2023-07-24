#include <philo.h>

void    *supervisor(void *philo_p)
{
    t_philo *philo;

    philo = (t_philo *)philo_p;
    while (!philo->prg->dead)
    {
        pthread_mutex_lock(&philo->lock);
        if ((get_time(philo->prg) >= philo->time_to_die) && !philo->eating)
            print_philo_state(DIED, philo);
        if (philo->eat_count == philo->prg->meals_nb)
        {
            pthread_mutex_lock(&philo->prg->lock);
            philo->prg->finished = 1;
            philo->eat_count++;
            pthread_mutex_unlock(&philo->prg->lock);
        }
        pthread_mutex_unlock(&philo->lock);
    }
    return ((void *)0);

}

void	*routine(void *philo_p)
{
    t_philo *philo;

    philo = (t_philo *)philo_p;
    philo->time_to_die = philo->prg->death_time + get_time(philo->prg);
    if (pthread_create(&(philo->t1), NULL, &supervisor, (void *)philo))
        print_err_prg("ERROR\n", (philo->prg));
    while (!philo->prg->dead)
    {
        take_forks(philo);
        printf("I am inside lopp, Philo\n");
        eat(philo);
        drop_forks(philo);
        print_philo_state(IS_THINKING, philo);
    }
    //pthread_join(philo->t1, NULL);
    return ((void *) 0);
}