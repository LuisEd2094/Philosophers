#include <philo.h>



void check_if_odd_philo_to_sleep(t_philo *philo)
{
    if (philo->id % 2 != 0)
    {            
        printf("%lu %d %s\n", get_time(philo->prg) - philo->prg->start_time, philo->id, IS_THINKING);
        if (philo->prg->eat_time < philo->prg->death_time)
            usleep(philo->prg->eat_time);
        else
            usleep(philo->prg->death_time );
    }    
}


void	*routine(void *philo_p)
{
    t_philo *philo;

    philo = (t_philo *)philo_p;
    update_num_threads(philo->prg, 1);
    while (!philo->prg->can_start)
        usleep(1);
    //printf("time to die%li current time%li death time %li", philo->prg->death_time, get_time(philo->prg), philo->time_to_die);
    //printf("Philo [%i] has started\n", philo->id);
    philo->time_to_die = philo->prg->start_time + (philo->prg->death_time / 1000);
    //printf("time to die %li current time %li death time %li\n", philo->prg->death_time, get_time(philo->prg), philo->time_to_die);
    if (!create_thread(&(philo->t1), &supervisor, (void *)philo))
    {
        update_num_threads(philo->prg, -1);
        return (NULL);
    }
    pthread_detach(philo->t1);
    check_if_odd_philo_to_sleep(philo);
    while (check_conditions_continue_thread(philo) && philo->can_continue)
    {
        printf("philo->[%i] started cycle\n", philo->id);
        take_forks(philo);
        if (philo->can_continue && check_conditions_continue_thread(philo))
            eat(philo);
        drop_forks(philo);
        if (philo->can_continue && check_conditions_continue_thread(philo))
            philo_sleep(philo);
    }
    //printf("philo [%i] left it's loop\n", philo->id);
    update_num_threads(philo->prg, -1);
    return (NULL);
}