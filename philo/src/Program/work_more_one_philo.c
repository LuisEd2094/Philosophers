/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_more_one_philo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:56:07 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/09/04 10:56:25 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	work_more_one_philo(t_prg *prg)
{
	int	i;

	i = 0;
	prg->can_start = 0;
	while (i < prg->philo_num)
	{
		if (!create_thread(&(prg->tid[i]), &(routine), &(prg->philos[i])))
			close_prg(prg);
		pthread_detach((prg->tid[i]));
		i++;
	}
	pthread_mutex_lock(&(prg->lock));
	prg->start_time = get_time(prg);
	prg->can_start = 1;
	pthread_mutex_unlock(&(prg->lock));
}
