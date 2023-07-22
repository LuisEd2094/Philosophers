#include <philo.h>
#include <stdlib.h>


static void    close_threads(t_prg *prg)
{
    int i;

    pthread_mutex_destroy(&(prg->lock));
    pthread_mutex_destroy(&(prg->write));
    i = -1;
    while (++i < prg->philo_num)
    {
        pthread_mutex_destroy(&(prg->forks[i]));
        pthread_mutex_destroy(&(prg->philos[i].lock));
    }

}
static void free_mallocs(t_prg *prg)
{
    if (prg->tid)
        free(prg->tid);
    if (prg->forks)
        free(prg->forks);
    if (prg->philos)
        free(prg->philos);
}

void    close_prg(t_prg *prg)
{
    close_threads(prg);
    free_mallocs(prg);
    if (prg->err)
        exit(prg->err);
    exit(0);
}