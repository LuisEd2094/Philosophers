/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:59:35 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/09/04 11:01:09 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <shared.h>

static void	init_prg(t_prg *prg, char **argv, int argc)
{
	prg->philo_num = ft_atoi(argv[1]);
	prg->death_time = ft_atoi(argv[2]) * 1000;
	prg->eat_time = ft_atoi(argv[3]) * 1000;
	prg->sleep_time = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		prg->meals_nb = ft_atoi(argv[5]);
	else
		prg->meals_nb = -1;
	prg->dead = 0;
	prg->finished = 0;
	prg->err = 0;
	prg->start_time = 0;
	prg->done = 0;
	if (!init_mutex(&(prg->lock), prg))
	{
		printf("%s", prg->err_msg);
		exit (prg->err);
	}
}

static void	malloc_data(t_prg *prg)
{
	prg->tid = (pthread_t *)malloc(sizeof(pthread_t) * prg->philo_num);
	prg->forks = (t_fork *)malloc(sizeof(t_fork) * prg->philo_num);
	prg->philos = (t_philo *)malloc(sizeof(t_philo) * \
	prg->philo_num);
	if (!prg->tid || !prg->forks || !prg->philos)
	{
		prg->err = MALLOC_ERROR;
		prg->err_msg = MALLOC_ERR_MSSG;
		close_on_failed_init(prg);
	}
}

static void	init_forks(t_prg *prg)
{
	int	i;

	i = 0;
	while (i < prg->philo_num)
	{
		if (!init_mutex(&prg->forks[i].lock, prg))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&(prg->forks[i].lock));
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

static void	init_philos(t_prg *prg)
{
	int	i;

	i = 0;
	while (i < prg->philo_num)
	{
		if (!init_mutex(&prg->philos[i].lock, prg))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&(prg->philos[i].lock));
			i = prg->philo_num - 1;
			while (i >= 0)
				pthread_mutex_destroy(&(prg->forks[i--].lock));
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

void	init(t_prg *prg, char **argv, int argc)
{
	init_prg(prg, argv, argc);
	malloc_data(prg);
	init_forks(prg);
	init_philos(prg);
}
