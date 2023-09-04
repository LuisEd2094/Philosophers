/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_prg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:45:17 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/09/04 10:45:55 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <stdlib.h>
#include <errno.h>

static void	close_mutex(t_prg *prg)
{
	int	i;

	pthread_mutex_destroy(&(prg->lock));
	i = -1;
	while (++i < prg->philo_num)
	{
		pthread_mutex_destroy(&(prg->forks[i].lock));
		pthread_mutex_destroy(&(prg->philos[i].lock));
	}
}

void	free_mallocs(t_prg *prg)
{
	if (prg->tid)
		free(prg->tid);
	if (prg->forks)
		free(prg->forks);
	if (prg->philos)
		free(prg->philos);
}

void	close_on_failed_init(t_prg *prg)
{
	free_mallocs(prg);
	pthread_mutex_destroy(&(prg->lock));
	printf("%s", prg->err_msg);
	exit(prg->err);
}

void	close_prg(t_prg *prg)
{
	while (prg->num_threads != 0)
		usleep(1000); 
	close_mutex(prg);
	free_mallocs(prg);
	if (prg->err)
	{
		printf("%s", prg->err_msg);
		exit(prg->err);
	}
	exit(0);
}
