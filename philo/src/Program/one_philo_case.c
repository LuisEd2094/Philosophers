#include <philo.h>

void    one_philo_case(t_prg *prg)
{
    prg->start_time = get_time(prg);
    printf("%li\n", prg->start_time);
    pthread_create(&(prg->tid[0]), NULL, &(routine), &(prg->philos[0]));
    pthread_detach(prg->tid[0]);
    while(!prg->dead)
        usleep(0);
    
}