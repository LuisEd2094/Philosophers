/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:48:01 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/10/15 13:28:49 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	check_if_odd_philo_to_sleep(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		print_philo_state(IS_THINKING, philo);
		if (philo->prg->eat_time < philo->prg->death_time)
			usleep(philo->prg->eat_time / 2);
		else
			usleep(philo->prg->death_time);
	}
}

void	check_if_finished(t_philo *philo)
{
	pthread_mutex_lock(&(philo->prg->lock));
	if (philo->prg->meals_nb > 0 && \
		philo->eat_count == philo->prg->meals_nb)
	{
		philo->prg->finished++;
		pthread_mutex_unlock(&(philo->prg->lock));
		pthread_mutex_lock(&(philo->lock));
		philo->can_continue = 0;
		pthread_mutex_unlock(&(philo->lock));
	}
	else
		pthread_mutex_unlock(&(philo->prg->lock));
}

void	execute_routine(t_philo *philo)
{
	take_forks(philo);
	get_locks(philo);
	if (check_conditions_continue_thread(philo))
	{
		unlock_locks(philo);
		eat(philo);
	}
	else
		unlock_locks(philo);
	drop_forks(philo);
	check_if_finished(philo);
	get_locks(philo);
	if (check_conditions_continue_thread(philo))
	{
		unlock_locks(philo);
		philo_sleep(philo);
	}
	else
		unlock_locks(philo);
}

void	wait_to_start(t_philo *philo)
{
	while (1)
	{
		get_locks(philo);
		if (philo->prg->can_start)
		{
			philo->time_to_die = philo->prg->start_time + \
								(philo->prg->death_time / 1000);
			unlock_locks(philo);
			break ;
		}
		unlock_locks(philo);
	}
}

void	*routine(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *)philo_p;
	wait_to_start(philo);
	pthread_detach(philo->t1);
	check_if_odd_philo_to_sleep(philo);
	while (1)
	{
		get_locks(philo);
		if (!check_conditions_continue_thread(philo))
			break ;
		unlock_locks(philo);
		execute_routine(philo);
	}
	return (unlock_locks(philo));
}
