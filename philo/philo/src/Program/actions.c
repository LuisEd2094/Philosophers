/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:44:20 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/09/18 10:10:38 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_sleep(t_philo *philo)
{
	print_philo_state(IS_SLEEPING, philo);
	usleep(philo->prg->sleep_time);
	if (philo->id % 2 != 0)
		print_philo_state(IS_THINKING, philo);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->l_fork->lock));
	pthread_mutex_unlock(&(philo->r_fork->lock));
}

void	get_forks(t_philo *philo, pthread_mutex_t *frst, pthread_mutex_t *scnd)
{
	if (philo->id % 2 == 0)
		print_philo_state(IS_THINKING, philo);
	pthread_mutex_lock(frst);
	print_philo_state(TAKE_FORK, philo);
	print_philo_state(IS_THINKING, philo);
	pthread_mutex_lock(scnd);
	print_philo_state(TAKE_FORK, philo);
}

void	take_forks(t_philo *philo)
{
	get_forks(philo, &(philo->l_fork->lock), &(philo->r_fork->lock));
}

void	eat(t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(&philo->lock);
	time = get_time(philo->prg);
	philo->time_to_die = time + \
						(philo->prg->death_time / 1000);
	philo->eat_count++;
	if (philo->prg->meals_nb > 0 && \
		philo->eat_count == philo->prg->meals_nb)
	{
		pthread_mutex_lock(&philo->prg->lock);
		philo->prg->finished++;
		pthread_mutex_unlock(&philo->prg->lock);
		philo->can_continue = 0;
	}
	pthread_mutex_unlock(&philo->lock);
	print_philo_state(IS_EATING, philo);
	usleep(philo->prg->eat_time);
}
