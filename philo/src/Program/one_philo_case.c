#include <philo.h>

void    one_philo_case(t_prg *prg)
{
    prg->start_time = get_time(prg);
    print_philo_state(IS_THINKING, &(prg->philos[0]));
    pthread_mutex_lock(&(prg->philos[0].l_fork->lock));
    print_philo_state(TAKE_FORK, &(prg->philos[0]));
    usleep(prg->death_time * 1000);
    print_philo_state(DIED, &(prg->philos[0]));
    pthread_mutex_unlock(&(prg->philos[0].l_fork->lock));
    close_prg(prg); 
}
