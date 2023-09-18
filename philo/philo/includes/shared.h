/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:03:52 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/09/04 11:04:15 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include <stdlib.h>

int		ft_atoi(const char *nptr);
int		check_if_int(char *str);
int		get_sign(char *argv);
int		ft_isspace(char chr);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
#endif
