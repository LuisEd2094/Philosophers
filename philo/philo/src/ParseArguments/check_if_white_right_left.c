/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_white_right_left.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:40:50 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/09/04 10:41:09 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <shared.h>

int	check_if_white_right_left(char *argv)
{
	if (ft_isspace(argv[0]) || ft_isspace(argv[ft_strlen(argv) - 1]))
		return (1);
	return (0);
}
