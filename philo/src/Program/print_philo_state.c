/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:47:44 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/09/04 10:47:53 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <string.h>
#include <shared.h>

void	print_philo_state(char *str, t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(&(philo->prg->lock));
	time = get_time(philo->prg) - (philo->prg->start_time);
	if (check_conditions_continue_thread(philo))
		printf("%llu %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&(philo->prg->lock));
}
