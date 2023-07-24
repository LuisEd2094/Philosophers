#include <philo.h>

void    one_philo_case(t_prg *prg)
{
    prg->start_time = get_time(prg);
    printf("right %i left %i\n", prg->philos[0].r_fork->av, prg->philos[0].l_fork->av);
    pthread_create(&(prg->tid[0]), NULL, &(routine), &(prg->philos[0]));
    pthread_detach(prg->tid[0]);
    while(!prg->dead)
        usleep(0);
    printf("CLOSING\n");
    close_prg(prg); 
}