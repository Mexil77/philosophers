/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:07:32 by emgarcia          #+#    #+#             */
/*   Updated: 2021/10/13 18:20:10 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_isnumber(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		number;

	i = 0;
	if (str[i] == '-' || !ft_isnumber(str[i]))
		return (-1);
	if (str[i] == '+')
		i++;
	number = 0;
	if (!ft_isnumber(str[i]))
		return (-1);
	i--;
	while (str[++i] && ft_isnumber(str[i]))
		number = 10 * number + str[i] - '0';
	if (str[i] && !ft_isnumber(str[i]))
		return (-1);
	return (number);
}
