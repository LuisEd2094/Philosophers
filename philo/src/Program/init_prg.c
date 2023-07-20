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
    prg->err = 0;
    init_thread(&(prg->write), prg);
    init_thread(&(prg->lock), prg);
}

void    malloc_data(t_prg *prg)
{
    prg->tid = (pthread_t *)malloc(sizeof(pthread_t) * prg->philo_num);
    prg->forks = (pthread_mutex_t *)malloc(sizeof (pthread_mutex_t) *\
     prg->philo_num);
    prg->philos = (t_philo *)malloc(sizeof (t_philo) *\
     prg->philo_num);
    if (!prg->tid || !prg->forks || !prg->philos)
    {
        prg->err = MALLOC_ERROR;
        print_err_prg(MALLOC_ERR_MSSG, prg);
    }

}

void    init_forks(t_prg *prg)
{
    int i;

    i = -1;
    while (++i < prg->philo_num)
        init_thread(&prg->forks[i], prg);
    i = 0;
    while (i < prg->philo_num)
    {
        prg->philos[i].l_fork = &prg->forks[i];
        if (i == 0)
            prg->philos[i].r_fork = &prg->forks[prg->philo_num - 1];
        else
            prg->philos[i].r_fork = &prg->forks[i - 1];
        i ++;
    }
}

void    init_philos(t_prg *prg)
{
    int i;

    i = 0;
    while (i < prg->philo_num)
    {
        init_thread(&(prg->philos[i].lock), prg);
        prg->philos[i].prg = prg;
        prg->philos[i].id = i + 1;
        prg->philos[i].time_to_die = prg->death_time;
        prg->philos[i].eat_count = 0;
        prg->philos[i].eating = 0;
        prg->philos[i].status = 0;
        i++;
    }
}

#include <stdio.h>

void    init(t_prg *prg, char **argv, int argc)
{
    init_prg(prg, argv, argc);
    malloc_data(prg);
    init_forks(prg);
    init_philos(prg);
}