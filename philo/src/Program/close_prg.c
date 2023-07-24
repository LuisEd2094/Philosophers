#include <philo.h>
#include <stdlib.h>

void destroy(pthread_mutex_t * mutex, char * str)
{
    pthread_mutex_unlock(mutex);
    if (pthread_mutex_destroy(mutex))
        printf("Failed %p %s\n", mutex, str);
}

static void    close_threads(t_prg *prg)
{
    int i;

    destroy(&(prg->lock),"Prg Lock");
    destroy(&(prg->write), "Prg Write");
    i = -1;
    while (++i < prg->philo_num)
    {
        destroy(&(prg->forks[i]), "Prg Fork");
        destroy(&(prg->philos[i].lock), "Prg Philo");
        //pthread_detach(prg->philos[i].t1);
        //pthread_detach(prg->tid[i]);
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