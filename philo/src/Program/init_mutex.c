#include <philo.h>

bool init_mutex(pthread_mutex_t *thread, t_prg *prg)
{
    if (pthread_mutex_init(thread, NULL))
    {
        prg->err = INIT_MUTEX_ERROR;
        prg->err_msg =INIT_MUTEX_ERR_MSSG;
        return (0);
    }
    return (1);
}