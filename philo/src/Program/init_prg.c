#include <philo.h>
#include <shared.h>


void    init_prg(t_prg *prg, char **argv, int argc)
{
    prg->philo_num = ft_atoi(argv[1]);
    prg->death_time = (uint64_t) ft_atoi(argv[2]);
    prg->eat_time = (uint64_t) ft_atoi(argv[3]);
	prg->sleep_time = (uint64_t) ft_atoi(argv[4]);
    if (argc == 6)
		prg->meals_nb = ft_atoi(argv[5]);
    prg->dead = 0;
    prg->finished = 0;
    if (pthread_mutex_init(&prg->write, NULL) ||
	        pthread_mutex_init(&prg->lock, NULL))
        print_err_prg(INIT_THREAD_ERROR,prg);    
}

void    init(t_prg *prg, char **argv, int argc)
{
    init_prg(prg, argv, argc);

}