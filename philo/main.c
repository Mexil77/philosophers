/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:59:29 by emgarcia          #+#    #+#             */
/*   Updated: 2021/10/06 22:33:36 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_iniphilo(t_philo *philos, size_t nphilos)
{
	size_t	i;

	i = -1;
	while (++i < nphilos)
	{
		philos[i].able = 1;
		philos[i].index = i + 1;
		philos[i].ownfork = 1;
		philos[i].forkl = 0;
		philos[i].forkr = 0;
	}
}

int	main(int argc, char const *argv[])
{
	t_table		table;
	size_t		i;
	pthread_t	*h;

	if (!argc)
		printf("%s\n", argv[0]);
	table.philosize = ft_atoi(argv[1]);
	h = malloc(sizeof(pthread_t) * table.philosize);
	if (!h)
		return (0);
	table.philos = malloc(sizeof(t_philo) * (table.philosize + 1));
	if (!table.philos)
		return (0);
	table.philos[table.philosize].able = 0;
	pthread_mutex_init(&table.printmutex, NULL);
	ft_iniphilo(table.philos, table.philosize);
	i = -1;
	while (table.philos[++i].able)
		pthread_create(&h[i], NULL, ft_philo, &table);
	i = -1;
	while (table.philos[++i].able)
		pthread_join(h[i], NULL);
	i = -1;
	while (table.philos[++i].able)
		ft_printphilo(table.philos[i]);
	free(table.philos);
	return (0);
}
