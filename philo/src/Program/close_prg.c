#include <philo.h>
#include <stdlib.h>


void    close_threads(t_prg *prg)
{
    pthread_mutex_destroy(&prg->lock);
    pthread_mutex_destroy(&prg->write);
}

void    close_prg(t_prg *prg)
{
    close_threads(prg);
    if (prg->err)
        exit(prg->err);
    exit(0);
}