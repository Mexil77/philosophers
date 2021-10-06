/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:57:57 by emgarcia          #+#    #+#             */
/*   Updated: 2021/10/06 22:50:22 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_printphilos(t_philo *philos)
{
	size_t	i;

	i = -1;
	while (philos[++i].able)
	{
		printf("philo No. : %zu\n", philos[i].index);
		printf("able : %zu\n", philos[i].able);
		printf("own fork : %zu\n", philos[i].ownfork);
		printf("left fork : %zu\n", philos[i].forkl);
		printf("right fork : %zu\n", philos[i].forkr);
		printf("\n");
	}
}

void	ft_printphilo(t_philo philo)
{
	printf("philo No. : %zu\n", philo.index);
	printf("own fork : %zu\n", philo.ownfork);
	printf("left fork : %zu\n", philo.forkl);
	printf("right fork : %zu\n", philo.forkr);
	printf("\n");
	//usleep(1000000);
}
