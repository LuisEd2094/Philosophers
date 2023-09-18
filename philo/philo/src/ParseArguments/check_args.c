/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:39:21 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/09/04 10:40:02 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <shared.h>

static void	check_values(int i, char *argv)
{
	int	value;

	if (!check_if_int(argv))
		print_err_args (ARG_INT_VALUE, NO_INT_VALUE);
	value = ft_atoi(argv);
	if (i == 1 && value > MAX_PHILOS)
		print_err_args (ARG_INVALID_PHILOS, INVALID_PHILOS);
	else if ((i >= 2 && i <= 4) && value > MAX_TIME)
		print_err_args (ARG_INVALID_TIME, INVALID_TIME);
	else if (value <= 0)
		print_err_args (ARG_ZERO_VALUE, INVALID_VALUE);
}

static void	ck_argv_content(char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!argv[i][0])
			print_err_args (ARG_ERROR_CONTENT, INVALID_CONTENT);
		check_values(i, argv[i]);
		i++;
	}
}

void	check_arguments(int argc, char *argv[])
{
	if ((argc < 5 || argc > 6))
		print_err_args(ARG_ERROR_NUM, INVALID_NUMBER);
	ck_argv_content(argv);
}
