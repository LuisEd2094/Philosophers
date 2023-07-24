#include <philo.h>
#include <stdlib.h>
#include <errno.h>


void destroy(pthread_mutex_t * mutex, char * str)
{

    int result = pthread_mutex_destroy(mutex); 
    if (result == 0) {
        printf("Mutex destroyed successfully.\n");
    } else {
        if (result == EBUSY) {
            printf("Cannot destroy the mutex. It's currently locked by a thread. %s\n", str);
        } else if (result == EINVAL) {
            printf("Invalid mutex object.\n");
        } else {
            printf("Error occurred while destroying the mutex. Error code: %d %s\n", result, str);
        }
    }

}

static void    close_threads(t_prg *prg)
{
    int i;

    destroy(&(prg->lock),"Prg Lock");
    i = -1;
    while (++i < prg->philo_num)
    {
        destroy(&(prg->forks[i].lock), "Prg Fork");
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
    while (prg->num_threads != 0)
        usleep(1); 
    close_threads(prg);
    free_mallocs(prg);
    printf("Num threads %i\n", prg->num_threads);
    if (prg->err)
        exit(prg->err);
    exit(0);
}