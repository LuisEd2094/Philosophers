#include <philo.h>
#include <string.h>

void    print_philo_state(char *str, t_philo *philo)
{
    uint64_t    time;

    time = get_time(philo->prg) - philo->prg->start_time;
    printf("%lu %d %s\n", time, philo->id, str);
}