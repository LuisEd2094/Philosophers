/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:46:47 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/09/04 10:47:08 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	init_mutex(pthread_mutex_t *thread, t_prg *prg)
{
	if (pthread_mutex_init(thread, NULL))
	{
		prg->err = INIT_MUTEX_ERROR;
		prg->err_msg = INIT_MUTEX_ERR_MSSG;
		return (0);
	}
	return (1);
}
