#include <philo.h>

void init_mutex(pthread_mutex_t *thread, t_prg *prg)
{
    if (pthread_mutex_init(thread, NULL))
    {
        prg->err = INIT_THREAD_ERROR;
        print_err_prg(INIT_THREAD_ERR_MSSG, prg);
    }
}