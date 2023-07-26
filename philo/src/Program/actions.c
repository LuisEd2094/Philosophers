#include <philo.h>

void    philo_sleep(t_philo *philo)
{
    print_philo_state(IS_SLEEPING, philo);
    usleep(philo->prg->sleep_time);
}

void    drop_forks(t_philo *philo)
{
    int i;

    if (philo->id == philo->l_fork->ids[0])
        i = 1;
    else
        i = 0;
    philo->r_fork->philo_id = philo->r_fork->ids[i];
    philo->l_fork->philo_id = philo->l_fork->ids[i];
    pthread_mutex_unlock(&(philo->l_fork->lock));
	pthread_mutex_unlock(&(philo->r_fork->lock));
}

bool    waiting_for_fork(t_philo *philo)
{
    if (philo->r_fork->philo_id != philo->id || philo->l_fork->philo_id != philo->id)
        return(1);
    return (0);
}

bool    wait_for_fork(t_philo *philo, t_prg *prg)
{
    while (check_conditions_continue_thread(prg) && waiting_for_fork(philo))
        usleep(1);
    if (prg->dead || prg->err)
        return (0);
    return (1); 
}

bool take_forks(t_philo *philo)
{
   // printf("PHILo ID %i ID right %i ID left %i\n", philo->id, philo->r_fork->philo_id, philo->l_fork->philo_id);
    if (!wait_for_fork(philo, philo->prg))
        return (0);
    pthread_mutex_lock(&philo->r_fork->lock);
    //philo->r_fork->av = 0;
    //printf("RIGHT %p ID %i\n", &(philo->r_fork), philo->id);
    print_philo_state(TAKE_FORK, philo);
    //if (!wait_for_fork(philo->l_fork, philo->prg))
    //{
      //  pthread_mutex_unlock(&(philo->r_fork->lock));
        //return (0);
   // }
    pthread_mutex_lock(&philo->l_fork->lock);
    //philo->l_fork->av = 0;
    //printf("left %p ID %i\n", &( philo->r_fork), philo->id);

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