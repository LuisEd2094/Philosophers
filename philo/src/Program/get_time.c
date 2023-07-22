#include <sys/time.h>
#include <philo.h>


uint64_t	get_time(t_prg *prg)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		{
            prg->err = TIME_ERROR;
            print_err_prg(TIME_ERR_MSG, prg);
        }
	return ((uint64_t)(tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}