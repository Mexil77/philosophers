/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:59:29 by emgarcia          #+#    #+#             */
/*   Updated: 2021/10/13 20:14:07 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	ft_initable(int argc, const char *argv[])
{
	t_table	table;

	table.tini = ft_timenow();
	table.philosize = ft_atoi(argv[1]);
	if (argc == 6)
		table.musteat = ft_atoi(argv[5]);
	else
		table.musteat = 0;
	table.died = 0;
	table.tdead = ft_atoi(argv[2]);
	table.teat = ft_atoi(argv[3]);
	table.tsleep = ft_atoi(argv[4]);
	table.philos = malloc(sizeof(t_philo) * table.philosize);
	pthread_mutex_init(&table.print, NULL);
	return (table);
}

void	ft_iniphilo(t_table *table)
{
	size_t	i;

	i = -1;
	while (++i < table->philosize)
	{
		table->philos[i].index = i + 1;
		table->philos[i].eatens = 0;
		table->philos[i].thread = malloc(sizeof(pthread_t));
		pthread_mutex_init(&table->philos[i].mutownfork, NULL);
		table->philos[i].table = table;
		table->philos[i].leat = table->tini;
	}
}

void	ft_createthread(t_philo	*philo)
{
	pthread_create(&(philo->thread), NULL, ft_philo, philo);
}

size_t	ft_validatedata(int argc, const char **argv)
{
	if (ft_atoi(argv[1]) < 0 || ft_atoi(argv[2]) < 0
		|| ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0
		|| (argc == 6 && ft_atoi(argv[5]) < 0))
		return (0);
	return (1);
}

int	main(int argc, char const *argv[])
{
	t_table	table;
	size_t	i;

	if (argc < 5 || argc > 6)
		printf("Wrong arguments.\n");
	if (!ft_validatedata(argc, argv))
		return (0);
	table = ft_initable(argc, argv);
	if (!table.philos)
		return (0);
	ft_iniphilo(&table);
	i = -1;
	while (++i < table.philosize)
		ft_createthread(&table.philos[i]);
	i = -1;
	while (++i < table.philosize)
		pthread_join(table.philos[i].thread, NULL);
	free(table.philos);
	return (0);
}
