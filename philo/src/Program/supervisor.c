/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:53:52 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/10/15 13:32:15 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	handle_death_of_philo(t_philo *philo, uint64_t time)
{
	pthread_mutex_lock(&(philo->prg->lock));
	if (philo->prg->dead == 0)
	{
		printf("%llu %d %s\n", time - (philo->prg->start_time), \
		philo->id, DIED);
		philo->prg->dead = 1;
	}
	pthread_mutex_unlock(&(philo->prg->lock));
	philo->can_continue = 0;
}

bool	check_if_super_continue(t_prg *prg)
{
	int	to_return;

	to_return = 0;
	pthread_mutex_lock(&(prg->lock));
	if (!(prg->dead) \
			&& !(prg->err) \
			&& (prg->finished != prg->philo_num))
		to_return = 1;
	pthread_mutex_unlock(&(prg->lock));
	return (to_return);
}

void	supervisor(t_prg *prg)
{
	uint64_t	time;
	t_philo		*philo;
	int			i;

	while (check_if_super_continue(prg))
	{
		i = 0;
		while (i < prg->philo_num)
		{
			philo = &(prg->philos[i]);
			pthread_mutex_lock(&(philo->lock));
			time = get_time(prg);
			if (philo->time_to_die > 0 && time > philo->time_to_die)
			{
				handle_death_of_philo(philo, time);
				pthread_mutex_unlock(&(philo->lock));
				break ;
			}
			pthread_mutex_unlock(&(philo->lock));
			i++;
		}
		usleep(400);
	}
}
