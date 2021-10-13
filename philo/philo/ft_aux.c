/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:57:57 by emgarcia          #+#    #+#             */
/*   Updated: 2021/10/13 16:43:12 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_alleaten(t_philo	*philo)
{
	size_t	i;

	i = -1;
	while (++i < philo->table->philosize)
		if (philo->table->philos[i].eatens < philo->table->musteat)
			return (0);
	return (1);
}

void	ft_printmsg(t_philo *philo, size_t color, char *msg)
{
	long	t;
	size_t	eatens;

	eatens = philo->eatens + 1;
	t = ft_timenow() - philo->table->tini;
	pthread_mutex_lock(&philo->table->print);
	if (!philo->table->died)
	{
		if (color == 0)
			printf(CYAN "[ %zu ] philo [%zu] %s\n" RESET, t, philo->index, msg);
		if (color == 1)
			printf(YELLOW"[ %zu ] philo [%zu] %s [%zu]\n"RESET, t,
				philo->index, msg, eatens);
		if (color == 2)
			printf(GREEN "[ %zu ] philo [%zu] %s\n" RESET, t, philo->index, msg);
		if (color == 3)
			printf(MAGENTA "[ %zu ] philo [%zu] %s\n" RESET, t,
				philo->index, msg);
		if (color == 4)
		{
			t = t + philo->table->tdead - ft_timenow() + philo->leat;
			printf(RED "[ %zu ] philo [%zu] %s\n" RESET, t, philo->index, msg);
		}
	}
	pthread_mutex_unlock(&philo->table->print);
}

void	ft_usleep(long time)
{
	long	now;

	now = ft_timenow();
	while (ft_timenow() - now < time)
		;
}

long	ft_timenow(void)
{
	struct timeval		tv;
	struct timezone		tz;

	gettimeofday(&tv, &tz);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_unlockforks(t_table *table)
{
	size_t	i;

	i = -1;
	while (++i < table->philosize)
		pthread_mutex_unlock(&table->philos[i].mutownfork);
}
