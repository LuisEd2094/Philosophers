/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:47:16 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/09/04 10:47:21 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	one_philo_case(t_prg *prg)
{
	prg->start_time = get_time(prg);
	print_philo_state(IS_THINKING, &(prg->philos[0]));
	pthread_mutex_lock(&(prg->philos[0].l_fork->lock));
	print_philo_state(TAKE_FORK, &(prg->philos[0]));
	usleep(prg->death_time);
	print_philo_state(DIED, &(prg->philos[0]));
	pthread_mutex_unlock(&(prg->philos[0].l_fork->lock));
}
