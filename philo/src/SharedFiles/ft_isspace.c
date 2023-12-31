/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:58:39 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/09/04 10:58:52 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char chr)
{
	if (chr == '\f' || chr == '\n' \
		|| chr == '\r' || chr == '\v' \
		|| chr == '\t' || chr == ' ' \
	|| chr == '\b')
	{
		return (1);
	}
	return (0);
}
