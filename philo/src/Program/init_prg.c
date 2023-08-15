#include <philo.h>
#include <shared.h>

static void    init_prg(t_prg *prg, char **argv, int argc)
{
    prg->philo_num = ft_atoi(argv[1]);
    prg->death_time = (uint64_t) ft_atoi(argv[2]);
    prg->eat_time = (uint64_t) ft_atoi(argv[3]) * 1000;
	prg->sleep_time = (uint64_t) ft_atoi(argv[4]) * 1000;
    if (argc == 6)
		prg->meals_nb = ft_atoi(argv[5]);
    else
        prg->meals_nb = -1;
    prg->dead = 0;
    prg->finished = 0;
    prg->err = 0;
    prg->start_time = 0;
    prg->num_threads = 0;
    if (!init_mutex(&(prg->lock), prg))
    {
        printf("%s", prg->err_msg);
        exit (prg->err);
    }
}

static void    malloc_data(t_prg *prg)
{
    //int i;

    prg->tid = (pthread_t *)malloc(sizeof(pthread_t) * prg->philo_num);
    prg->forks = (t_fork *)malloc(sizeof (t_fork) * prg->philo_num);
    prg->philos = (t_philo *)malloc(sizeof (t_philo) *\
     prg->philo_num);
    if (!prg->tid || !prg->forks || !prg->philos)
    {
        prg->err = MALLOC_ERROR;
        prg->err_msg = MALLOC_ERR_MSSG;
        close_on_failed_init(prg);
    }
   // i = 0;
    /*while (i < prg->philo_num)
        prg->tid[i++] = 0;*/
}

static void    init_forks(t_prg *prg)
{
    int i;

    i = 0;
    while (i < prg->philo_num)
    {
        if (i != 0 && i != prg->philo_num - 1)
        {
            if (i % 2 == 0)
            {
                prg->forks[i].ids[0] = i + 1;
                prg->forks[i].ids[1] = i + 2;
            }
            else
            {
                prg->forks[i].ids[1] = i + 1;
                prg->forks[i].ids[0] = i + 2;
            }

        }
        else
        {
            prg->forks[i].ids[0] = 1;
            if (i == 0)
                prg->forks[i].ids[1] = 2;
            else
                prg->forks[i].ids[1] = prg->philo_num;
        }

        prg->forks[i].philo_id = prg->forks[i].ids[0];
        if (!init_mutex(&prg->forks[i].lock, prg))
        {        
            while (--i >= 0)
                destroy(&(prg->forks[i].lock), "fork");
            close_on_failed_init(prg);
        }
        prg->philos[i].l_fork = &prg->forks[i];
        if (i == 0)
            prg->philos[i].r_fork = &prg->forks[prg->philo_num - 1];
        else
            prg->philos[i].r_fork = &prg->forks[i - 1];
        i++;
    }
}

static void    init_philos(t_prg *prg)
{
    int i;

    i = 0;
    while (i < prg->philo_num)
    {
        if (!init_mutex(&prg->philos[i].lock, prg))
        {        
            while (--i >= 0)
                destroy(&(prg->philos[i].lock), "philos");
            i = prg->philo_num - 1;
            while (i >= 0)
                destroy(&(prg->forks[i--].lock), "fork");
            close_on_failed_init(prg);
        }
        prg->philos[i].prg = prg;
        prg->philos[i].id = i + 1;
        prg->philos[i].time_to_die = 0;
        prg->philos[i].eat_count = 0;
        prg->philos[i].can_continue = 1;
        prg->philos[i].t1 = 0;
        i++;
    }
}

void    init(t_prg *prg, char **argv, int argc)
{
    init_prg(prg, argv, argc);
    malloc_data(prg);
    init_forks(prg);
    init_philos(prg);
}