#include <philo.h>

void    *supervisor(void *philo_p)
{
    t_philo *philo;

    philo = (t_philo *)philo_p;
    update_num_threads(philo->prg, 1);
    while (!(philo->prg->dead) && !(philo->prg->err) && (philo->prg->finished != philo->prg->philo_num))
    {
        pthread_mutex_lock(&(philo->lock));
        if ((get_time(philo->prg) >= philo->time_to_die))
        {
            pthread_mutex_lock(&(philo->prg->lock));
            philo->prg->dead = 1;
            print_philo_state(DIED, philo);
            pthread_mutex_unlock(&(philo->prg->lock));
            pthread_mutex_unlock(&philo->lock);
            break ;
        }
        if (philo->eat_count == philo->prg->meals_nb)
        {
            pthread_mutex_lock(&(philo->prg->lock));
            philo->prg->finished++;
            pthread_mutex_unlock(&(philo->prg->lock));
        }
        pthread_mutex_unlock(&philo->lock);
    }
    update_num_threads(philo->prg, -1);
    return (NULL);
}


void	*routine(void *philo_p)
{
    t_philo *philo;

    philo = (t_philo *)philo_p;
    update_num_threads(philo->prg, 1);
    while (!philo->prg->can_start)
        usleep(10);
    //printf("time to die%li current time%li death time %li", philo->prg->death_time, get_time(philo->prg), philo->time_to_die);
    printf("Philo [%i] has started\n", philo->id);
    philo->time_to_die = philo->prg->death_time + get_time(philo->prg);
    //printf("time to die %li current time %li death time %li\n", philo->prg->death_time, get_time(philo->prg), philo->time_to_die);
    if (!create_thread(&(philo->t1), &supervisor, (void *)philo))
    {
        update_num_threads(philo->prg, -1);
        return (NULL);
    }
    pthread_detach(philo->t1);
    while (check_conditions_continue_thread(philo) && !check_if_reached_num_meals(philo))
    {
        if (!take_forks(philo))
            break ;
        //if (check_conditions_continue_thread(philo))
            eat(philo);
        //if (check_conditions_continue_thread(philo))
            drop_forks(philo);
        //if (check_conditions_continue_thread(philo))
            philo_sleep(philo);
        //if (check_conditions_continue_thread(philo))
            print_philo_state(IS_THINKING, philo);
    }
    update_num_threads(philo->prg, -1);
    return (NULL);
}