#include <philo.h>

void    *supervisor(void *philo_p)
{
    t_philo *philo;

    philo = (t_philo *)philo_p;
    update_num_threads(philo->prg, 1);
    printf("{%lu} time_to_die [%i] philo id\n", philo->time_to_die, philo->id);
    while (!(philo->prg->dead) && !(philo->prg->err) && (philo->prg->finished != philo->prg->philo_num))
    {
        usleep(philo->prg->death_time * 1000);
        pthread_mutex_lock(&(philo->lock));
        printf("time since start:{%lu} {%lu} time_to_die {%lu} current time [%i] philo id\n", (get_time(philo->prg) - (philo->prg->start_time)),philo->time_to_die, get_time(philo->prg), philo->id);
        if ((get_time(philo->prg) >= philo->time_to_die))
        {
            pthread_mutex_lock(&(philo->prg->lock));
            if (philo->prg->dead == 0)
            {
                philo->prg->dead = 1;
                print_philo_state(DIED, philo);
            }
            pthread_mutex_unlock(&(philo->prg->lock));
            philo->can_continue = 0;
            pthread_mutex_unlock(&philo->lock);
            break ;
        }
        if (philo->eat_count == philo->prg->meals_nb && philo->prg->finished <  philo->prg->philo_num)
        {
            pthread_mutex_lock(&(philo->prg->lock));
            if(philo->can_continue)
                philo->prg->finished++;
            philo->can_continue = 0;
            if (philo->prg->finished >= philo->prg->philo_num)
            {
                //printf("philo->prg->finished[%i] philo supervisor [%i] philo->prg->philo_num [%i] counted to finish\n", philo->prg->finished, philo->id, philo->prg->philo_num);


                pthread_mutex_unlock(&(philo->prg->lock));
                pthread_mutex_unlock(&philo->lock);
                break ;
            }
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
        if (philo->can_continue)
            eat(philo);
        drop_forks(philo);
        if (philo->can_continue)
            philo_sleep(philo);
        if (philo->can_continue)
            print_philo_state(IS_THINKING, philo);
    }
    printf("philo [%i] left it's loop\n", philo->id);
    update_num_threads(philo->prg, -1);
    return (NULL);
}