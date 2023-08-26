/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:59:52 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/05/10 17:54:15 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>


uint64_t	ft_atoi(const char *nptr)
{
	uint64_t	nmr;
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	nmr = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nmr = (nmr * 10) + (nptr[i] - '0');
		i++;
	}
	return (nmr * sign);
}
