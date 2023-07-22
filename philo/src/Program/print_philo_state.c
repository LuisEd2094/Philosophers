#include <philo.h>
#include <string.h>

void    print_philo_state(char *str, t_philo *philo)
{
    uint64_t    time;

    pthread_mutex_lock(&(philo->prg->write));
    time = get_time(philo->prg) - philo->prg->start_time;
    if (strcmp("DEAD", str) == 0)//NEED TO GET MY FT_//
    {
        printf("%lu %d %s\n", time, philo->id, str);
        philo->prg->dead = 1;
        printf("%i\n", philo->prg->dead);
    }
    if (!philo->prg->dead)
		  printf("%lu %d %s\n", time, philo->id, str);
    pthread_mutex_unlock(&(philo->prg->write));
}