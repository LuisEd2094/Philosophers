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


bool	check_conditions_continue_thread(t_philo *philo)
{
    if (philo->prg->dead || philo->prg->err || \
        !philo->can_continue)
        return (0);
    return (1); 
}