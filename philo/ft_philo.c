/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:41:47 by emgarcia          #+#    #+#             */
/*   Updated: 2021/10/06 22:50:47 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_getforks(t_table *table, size_t i)
{
	if (i + 1 == table->philosize)
		table->philos[0].ownfork = 0;
	else
		table->philos[i + 1].ownfork = 0;
	table->philos[i].ownfork = 0;
	table->philos[i].forkl = 1;
	printf("[ seg ] philo[%zu] has taken a fork\n", i + 1);
	table->philos[i].forkr = 1;
	printf("[ seg ] philo[%zu] has taken a fork\n", i + 1);
}

size_t	ft_cangetforks(t_table *table, size_t i)
{
	size_t	il;
	size_t	ir;

	il = i;
	ir = i + 1;
	if (i + 1 == table->philosize)
		ir = 0;
	if (table->philos[il].ownfork && table->philos[ir].ownfork)
		return (1);
	return (0);
}

void	*ft_philo(void *ta)
{
	t_table			*table;
	static size_t	i = 0;

	table = (t_table *)ta;
	pthread_mutex_lock(&table->printmutex);
	if (ft_cangetforks(table, i))
		ft_getforks(table, i);
	i++;
	pthread_mutex_unlock(&table->printmutex);
	return (NULL);
}
