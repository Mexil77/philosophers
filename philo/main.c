/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:59:29 by emgarcia          #+#    #+#             */
/*   Updated: 2021/10/10 20:57:52 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_iniphilo(t_table *table)
{
	size_t	i;

	i = -1;
	while (++i < table->philosize)
	{
		table->philos[i].able = 1;
		table->philos[i].index = i + 1;
		table->philos[i].ownfork = 2;
		table->philos[i].thread = malloc(sizeof(pthread_t));
		pthread_mutex_init(&table->philos[i].mutownfork, NULL);
		pthread_mutex_init(&table->philos[i].print, NULL);
		table->philos[i].table = table;
		table->philos[i].leat = time(0);
	}
}

int	main(int argc, char const *argv[])
{
	t_table		table;
	size_t		i;

	if (!argc)
		printf("%s\n", argv[0]);
	table.tini = time(0);
	table.philosize = ft_atoi(argv[1]);
	table.philos = malloc(sizeof(t_philo) * (table.philosize + 1));
	if (!table.philos)
		return (0);
	table.philos[table.philosize].able = 0;
	ft_iniphilo(&table);
	i = -1;
	while (table.philos[++i].able)
		pthread_create(&table.philos[i].thread, NULL, ft_philo, &table.philos[i]);
	i = -1;
	while (table.philos[++i].able)
		pthread_join(table.philos[i].thread, NULL);
	//ft_printphilos(table.philos);
	free(table.philos);
	return (0);
}
