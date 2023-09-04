/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:46:03 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/09/04 10:46:39 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <philo.h>

uint64_t	get_time(t_prg *prg)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
	{
		prg->err = TIME_ERROR;
		prg->err_msg = TIME_ERR_MSG;
		return (0);
	}
	return ((uint64_t)(tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
