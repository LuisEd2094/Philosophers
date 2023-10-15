/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:59:11 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/10/15 13:27:54 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <philo.h>

int	main(int argc, char *argv[])
{
	t_prg	prg;

	parse_arguments(argc, argv);
	init(&prg, argv, argc);
	if (prg.philo_num == 1)
		one_philo_case(&prg);
	else
		work_more_one_philo(&prg);
	close_prg(&prg);
	return (0);
}
