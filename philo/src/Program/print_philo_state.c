#include <philo.h>
#include <string.h>
#include <shared.h>

void    print_philo_state(char *str, t_philo *philo)
{
    uint64_t    time;

    time = get_time(philo->prg) - (philo->prg->start_time);
    pthread_mutex_lock(&(philo->prg->lock));
    if (check_conditions_continue_thread(philo))
        printf("%lu %d %s\n", time, philo->id, str);
    pthread_mutex_unlock(&(philo->prg->lock));


}
