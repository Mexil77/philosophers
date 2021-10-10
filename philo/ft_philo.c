/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:41:47 by emgarcia          #+#    #+#             */
/*   Updated: 2021/10/10 22:16:57 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *phi)
{
	size_t	ir;

	ir = phi->index;
	if (ir == phi->table->philosize)
		ir = 0;
	if (phi->index % 2 == 0)
	{
		pthread_mutex_lock(&phi->table->philos[ir].mutownfork);
		pthread_mutex_lock(&phi->table->philos[ir].print);
		printf(CYAN "[ %zu ] philo[%zu] has taken a fork\n" RESET, time(0) - phi->table->tini, phi->index);
		pthread_mutex_unlock(&phi->table->philos[ir].print);
		pthread_mutex_lock(&phi->mutownfork);
		pthread_mutex_lock(&phi->print);
		printf(CYAN "[ %zu ] philo[%zu] has taken a fork\n" RESET, time(0) - phi->table->tini, phi->index);
		pthread_mutex_unlock(&phi->print);
	}
	else
	{
		pthread_mutex_lock(&phi->mutownfork);
		pthread_mutex_lock(&phi->print);
		printf(CYAN "[ %zu ] philo[%zu] has taken a fork\n" RESET, time(0) - phi->table->tini, phi->index);
		pthread_mutex_unlock(&phi->print);
		pthread_mutex_lock(&phi->table->philos[ir].mutownfork);
		pthread_mutex_lock(&phi->table->philos[ir].print);
		printf(CYAN "[ %zu ] philo[%zu] has taken a fork\n" RESET, time(0) - phi->table->tini, phi->index);
		pthread_mutex_unlock(&phi->table->philos[ir].print);
	}
	printf(YELLOW "[ %zu ] philo[%zu] is eating\n" RESET, time(0) - phi->table->tini, phi->index);
	usleep(1000000);
	phi->leat = time(0);
	pthread_mutex_unlock(&phi->table->philos[ir].mutownfork);
	pthread_mutex_unlock(&phi->mutownfork);
}

void	ft_think(t_philo *phi)
{
	pthread_mutex_lock(&phi->print);
	printf(GREEN "[ %zu ] philo[%zu] is thinking\n" RESET, time(0) - phi->table->tini, phi->index);
	pthread_mutex_unlock(&phi->print);
}

void	ft_sleep(t_philo *phi)
{
	pthread_mutex_lock(&phi->print);
	printf(MAGENTA "[ %zu ] philo[%zu] is sleeping\n" RESET, time(0) - phi->table->tini, phi->index);
	pthread_mutex_unlock(&phi->print);
	usleep(2000000);
}

void	*ft_philo(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	while (1)
	{
		ft_eat(philo);
		ft_think(philo);
		ft_sleep(philo);
	}
	return (NULL);
}
