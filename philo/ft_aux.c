/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:57:57 by emgarcia          #+#    #+#             */
/*   Updated: 2021/10/09 23:07:14 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_printphilo(t_philo philo)
{
	printf("philo No. : %zu\n", philo.index);
	printf("ownfork : %zu\n", philo.ownfork);
	printf("\n");
}

void	ft_printphilos(t_philo *philos)
{
	size_t	i;

	i = -1;
	while (philos[++i].able)
		ft_printphilo(philos[i]);
}
