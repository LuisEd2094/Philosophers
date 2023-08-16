#include <philo.h>

void    philo_sleep(t_philo *philo)
{
    print_philo_state(IS_SLEEPING, philo);
    usleep(philo->prg->sleep_time);
}

void    drop_forks(t_philo *philo)
{
    pthread_mutex_unlock(&(philo->l_fork->lock));
	pthread_mutex_unlock(&(philo->r_fork->lock));
}

bool    waiting_for_fork(t_philo *philo)
{
    //if (philo->id == 4)
      //  printf("right %i left %i\n",philo->r_fork->philo_id ,philo->l_fork->philo_id);
    
    if (philo->r_fork->philo_id != philo->id || philo->l_fork->philo_id != philo->id)
        return(1);
    return (0);
}

bool    wait_for_fork(t_philo *philo, t_prg *prg)
{
    while (check_conditions_continue_thread(philo) && waiting_for_fork(philo))
        usleep(1);
    if (prg->dead || prg->err)
        return (0);
    return (1); 
}

bool    start_taking_forks(t_philo *philo, pthread_mutex_t *first, pthread_mutex_t *second)
{
        print_philo_state(IS_THINKING, philo);
        pthread_mutex_lock(first);
        print_philo_state(TAKE_FORK, philo);
        print_philo_state(IS_THINKING, philo);
        pthread_mutex_lock(second);
        print_philo_state(TAKE_FORK, philo);
        return (1); 
}

bool take_forks(t_philo *philo)
{
   // printf("PHILo ID %i ID right %i ID left %i\n", philo->id, philo->r_fork->philo_id, philo->l_fork->philo_id);
    //if (!wait_for_fork(philo, philo->prg))
      //  return (0);
    if (philo->id != philo->prg->philo_num)
    {
        start_taking_forks(philo, &(philo->l_fork->lock), &(philo->r_fork->lock));
        /*
        print_philo_state(IS_THINKING, philo);
        pthread_mutex_lock(&philo->l_fork->lock);
        print_philo_state(TAKE_FORK, philo);
        print_philo_state(IS_THINKING, philo);
        pthread_mutex_lock(&philo->r_fork->lock);
        print_philo_state(TAKE_FORK, philo);*/
    }
    else
    {
        start_taking_forks(philo, &(philo->r_fork->lock), &(philo->l_fork->lock));
/*
        print_philo_state(IS_THINKING, philo);
        pthread_mutex_lock(&philo->r_fork->lock);
        print_philo_state(TAKE_FORK, philo);
        print_philo_state(IS_THINKING, philo);
        pthread_mutex_lock(&philo->l_fork->lock);
        print_philo_state(TAKE_FORK, philo);*/
    }

    //philo->r_fork->av = 0;
    //printf("RIGHT %p ID %i\n", &(philo->r_fork), philo->id);
    //if (!wait_for_fork(philo->l_fork, philo->prg))
    //{
      //  pthread_mutex_unlock(&(philo->r_fork->lock));
        //return (0);
   // }

    //philo->l_fork->av = 0;
    //printf("left %p ID %i\n", &( philo->r_fork), philo->id);

    return (1);
}

void    eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->lock);
    philo->time_to_die = get_time(philo->prg) + philo->prg->death_time;
    printf("%lu time_to_die after updating in eat [%i] philo ID \n", philo->time_to_die, philo->id);
    print_philo_state(IS_EATING, philo);
    usleep(philo->prg->eat_time);
    //printf("i am updating eatcount from philo : {%i}\n", philo->id);
    philo->eat_count++;
    if (philo->eat_count == philo->prg->meals_nb)
    {
        pthread_mutex_lock(&philo->prg->lock);
        philo->prg->finished++;
        pthread_mutex_unlock(&philo->prg->lock);
        philo->can_continue = 0;
    }
    pthread_mutex_unlock(&philo->lock);
}