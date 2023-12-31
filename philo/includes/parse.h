/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:02:02 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/09/04 11:02:23 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stddef.h>
# include <pthread.h>

typedef enum s_error
{
	OK,
	INVALID_NUMBER,
	INVALID_CONTENT,
	INVALID_PHILOS,
	INVALID_TIME,
	INVALID_VALUE,
	NO_INT_VALUE
}	t_error_code;

# define MAX_PHILOS 300
# define MAX_TIME	20000

# define ARG_ERROR_NUM "Invalid number of arguments. See subject.\n"
# define ARG_ERROR_CONTENT "One of your arguments is invalid, \
check your arguments and try again.\n"
# define ARG_INVALID_PHILOS "You have given too many Philos, \
the max number accepted is 300.\n"
# define ARG_INVALID_TIME "The max time to die, eat and/or think accepted is  \
20000.\n"
# define ARG_ZERO_VALUE "Arguments can't have zero or negative value.\n"
# define ARG_INT_VALUE "Please provide an int value for all arguments.\n"

void	print_err_args(char *err_mssg, int err);
void	check_arguments(int argc, char *argv[]);
void	remove_white_space(char *argv);
int		check_if_white_right_left(char *argv);
void	check_and_remove_zeros(char *str);

#endif
