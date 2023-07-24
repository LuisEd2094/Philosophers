#include <philo.h>

void    philo_sleep(t_philo *philo)
{
    print_philo_state(IS_SLEEPING, philo);
    usleep(philo->prg->sleep_time);
}

void    drop_forks(t_philo *philo)
{
    pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);

}

void take_forks(t_philo *philo)
{
    pthread_mutex_lock(philo->r_fork);
    print_philo_state(TAKE_FORK, philo);
    pthread_mutex_lock(philo->l_fork);
    print_philo_state(TAKE_FORK, philo);
}

void    eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->lock);
    philo->eating = 1;
    philo->time_to_die = get_time(philo->prg) + philo->prg->death_time;
    print_philo_state(IS_EATING, philo);
    philo->eat_count++;
    usleep(philo->prg->eat_time);
    philo->eating = 0;
    pthread_mutex_unlock(&philo->lock);
}