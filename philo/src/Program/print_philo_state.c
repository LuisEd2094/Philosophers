#include <philo.h>
#include <string.h>
#include <shared.h>

void    print_philo_state(char *str, t_philo *philo)
{
    uint64_t    time;

    time = get_time(philo->prg) - (philo->prg->start_time);
    if (!philo->prg->dead)
        printf("%llu %d %s\n", time, philo->id, str);
    else if(ft_strcmp(str, "died") == 0)
        printf("%llu %d %s\n", time, philo->id, str);

}
