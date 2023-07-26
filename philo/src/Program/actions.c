#include <philo.h>

void    philo_sleep(t_philo *philo)
{
    print_philo_state(IS_SLEEPING, philo);
    usleep(philo->prg->sleep_time);
}

void    drop_forks(t_philo *philo)
{
    philo->l_fork->av = 1;
    pthread_mutex_unlock(&(philo->l_fork->lock));
    philo->r_fork->av = 1;
	pthread_mutex_unlock(&(philo->r_fork->lock));
}

bool    wait_for_fork(t_fork *fork, t_prg *prg)
{
    while (!fork->av && !prg->dead && check_conditions_continue_thread(prg))
        usleep(1);
    if (fork->av)
        return (1);
    return (0); 
}

bool take_forks(t_philo *philo)
{
    if (!wait_for_fork(philo->r_fork, philo->prg))
        return (0);
    pthread_mutex_lock(&philo->r_fork->lock);
    philo->r_fork->av = 0;
    print_philo_state(TAKE_FORK, philo);
    if (!wait_for_fork(philo->l_fork, philo->prg))
    {
        pthread_mutex_unlock(&(philo->r_fork->lock));
        return (0);
    }
    pthread_mutex_lock(&philo->l_fork->lock);
    philo->l_fork->av = 0;
    print_philo_state(TAKE_FORK, philo);
    return (1);
}

void    eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->lock);
    philo->time_to_die = get_time(philo->prg) + philo->prg->death_time;
    print_philo_state(IS_EATING, philo);
    philo->eat_count++;
    usleep(philo->prg->eat_time);
    pthread_mutex_unlock(&philo->lock);
}