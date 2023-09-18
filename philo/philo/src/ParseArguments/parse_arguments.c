/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:41:16 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/09/04 10:41:50 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>

static void	check_and_remove_white_space(char *argv)
{
	if (check_if_white_right_left(argv))
		remove_white_space(argv);
}

void	parse_arguments(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		check_and_remove_white_space(argv[i]);
		check_and_remove_zeros(argv[i]);
		i++;
	}
	check_arguments(argc, argv);
}
