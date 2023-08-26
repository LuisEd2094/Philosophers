#include <philo.h>

void    philo_sleep(t_philo *philo)
{
    print_philo_state(IS_SLEEPING, philo);
    usleep(philo->prg->sleep_time);
    if (philo->id % 2 != 0)
        print_philo_state(IS_THINKING, philo);
}

void    drop_forks(t_philo *philo)
{
    pthread_mutex_unlock(&(philo->l_fork->lock));
	pthread_mutex_unlock(&(philo->r_fork->lock));
}

void    get_forks(t_philo *philo, pthread_mutex_t *frst, pthread_mutex_t *scnd)
{
    if (philo->id % 2 == 0) 
        print_philo_state(IS_THINKING, philo);
    pthread_mutex_lock(frst);
    print_philo_state(TAKE_FORK, philo);
    print_philo_state(IS_THINKING, philo);
    pthread_mutex_lock(scnd);
    print_philo_state(TAKE_FORK, philo);
}

void take_forks(t_philo *philo)
{
    if (philo->id != philo->prg->philo_num)
        get_forks(philo, &(philo->l_fork->lock), &(philo->r_fork->lock));
    else
        get_forks(philo, &(philo->r_fork->lock), &(philo->l_fork->lock));
}

void    eat(t_philo *philo)
{
    uint64_t time;

    pthread_mutex_lock(&philo->lock);
    time = get_time(philo->prg);
    philo->time_to_die = time + \
                         (philo->prg->death_time / 1000);
    print_philo_state(IS_EATING, philo);
    usleep(philo->prg->eat_time);
    philo->eat_count++;
    if (philo->prg->meals_nb > 0 && \
        philo->eat_count == philo->prg->meals_nb)
    {
        pthread_mutex_lock(&philo->prg->lock);
        philo->prg->finished++;
        pthread_mutex_unlock(&philo->prg->lock);
        philo->can_continue = 0;
    }
    pthread_mutex_unlock(&philo->lock);
}