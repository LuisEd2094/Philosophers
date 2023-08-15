#include <philo.h>

void    update_num_threads(t_prg *prg, int value)
{
    pthread_mutex_lock(&(prg->lock));
    prg->num_threads += value;
    pthread_mutex_unlock(&(prg->lock));
}

bool    create_thread(pthread_t *tid, void *(*f)(void *), t_philo *philo_p)
{
    if (pthread_create(tid, NULL, f, (void *)philo_p))
    {
        philo_p->prg->err = THREAD_CREATE_ERROR;
        philo_p->prg->err_msg = THREAD_CREATE_ERROR_MSG;
        return (0);
    }
    return (1);
}

bool    check_if_reached_num_meals(t_philo *philo)
{
    //printf("[%i] checked if number of meals\nfinished [%i]\nmeals_count [%i]\n",philo->prg->finished == philo->prg->meals_nb, philo->prg->finished, philo->prg->meals_nb);
    if (philo->eat_count == philo->prg->meals_nb)
        return (1);
    return (0);
}

bool	check_conditions_continue_thread(t_philo *philo)
{
    if (philo->prg->dead || philo->prg->err)
        return (0);
    return (1); 
}