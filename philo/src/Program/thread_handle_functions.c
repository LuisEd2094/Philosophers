/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_handle_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:55:54 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/10/15 13:32:37 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	create_thread(pthread_t *tid, void *(*f)(void *), t_philo *philo_p)
{
	pthread_mutex_lock(&(philo_p->prg->lock));
	if (pthread_create(tid, NULL, f, (void *)philo_p))
	{
		philo_p->prg->err = THREAD_CREATE_ERROR;
		philo_p->prg->err_msg = THREAD_CREATE_ERROR_MSG;
		pthread_mutex_unlock(&(philo_p->prg->lock));
		return (0);
	}
	pthread_mutex_unlock(&(philo_p->prg->lock));
	return (1);
}

void	get_locks(t_philo *philo)
{
	pthread_mutex_lock(&(philo->prg->lock));
	pthread_mutex_lock(&(philo->lock));
}

void	*unlock_locks(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->lock));
	pthread_mutex_unlock(&(philo->prg->lock));
	return (NULL);
}

bool	check_conditions_continue_thread(t_philo *philo)
{
	int	to_return;

	to_return = 1;
	if (philo->prg->dead || philo->prg->err || \
		!philo->can_continue)
		to_return = 0;
	return (to_return);
}
