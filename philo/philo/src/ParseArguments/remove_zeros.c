/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_zeros.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:42:34 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/09/04 10:42:51 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_and_remove_zeros(char *str)
{
	int	i;
	int	k;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] != '0')
		return ;
	k = i;
	while (str[i] == '0')
		i++;
	while (str[i])
		str[k++] = str[i++];
	while (str[k])
		str[k++] = '\0';
}
