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
    //printf("philo[%i] droped his left fork id :[%i]\n", philo->id, philo->l_fork->fork_id);
	pthread_mutex_unlock(&(philo->r_fork->lock));
    //printf("philo[%i] droped his right fork id :[%i]\n", philo->id, philo->r_fork->fork_id);
}

void    start_taking_forks(t_philo *philo, pthread_mutex_t *first, pthread_mutex_t *second)
{
    if (philo->id % 2 == 0) 
        print_philo_state(IS_THINKING, philo);
    pthread_mutex_lock(first);
    print_philo_state(TAKE_FORK, philo);
    print_philo_state(IS_THINKING, philo);
    pthread_mutex_lock(second);
    print_philo_state(TAKE_FORK, philo);
}

void take_forks(t_philo *philo)
{
   // printf("PHILo ID %i ID right %i ID left %i\n", philo->id, philo->r_fork->philo_id, philo->l_fork->philo_id);
    //if (!wait_for_fork(philo, philo->prg))
      //  return (0);
    if (philo->id != philo->prg->philo_num)
        start_taking_forks(philo, &(philo->l_fork->lock), &(philo->r_fork->lock));
    else
        start_taking_forks(philo, &(philo->r_fork->lock), &(philo->l_fork->lock));
}

void    eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->lock);
    philo->time_to_die = get_time(philo->prg) + philo->prg->death_time;
    print_philo_state(IS_EATING, philo);
    usleep(philo->prg->eat_time);
    philo->eat_count++;
    if (philo->prg->meals_nb > 0 && philo->eat_count == philo->prg->meals_nb)
    {
        pthread_mutex_lock(&philo->prg->lock);
        philo->prg->finished++;
        pthread_mutex_unlock(&philo->prg->lock);
        philo->can_continue = 0;
    }
    pthread_mutex_unlock(&philo->lock);
}