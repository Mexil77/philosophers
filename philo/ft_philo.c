/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:41:47 by emgarcia          #+#    #+#             */
/*   Updated: 2021/10/12 22:12:58 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->print);
	ft_printmsg(philo, 4, "is dead");
	pthread_mutex_unlock(&philo->print);
	exit(0);
}

void	ft_eat(t_philo *philo)
{
	size_t	ir;

	ir = philo->index;
	if (ir == philo->table->philosize)
		ir = 0;
	if (philo->index > 1)
		usleep(100);
	if (philo->index == philo->table->philosize)
		ft_forkright(philo, ir);
	else
		ft_forkleft(philo, ir);
	if (ft_timenow() - philo->leat + philo->table->teat >= philo->table->tdead)
		ft_dead(philo);
	usleep(1000);
	pthread_mutex_lock(&philo->print);
	ft_printmsg(philo, 1, "is eating");
	pthread_mutex_unlock(&philo->print);
	usleep(philo->table->teat * 1000);
	philo->leat = ft_timenow();
	pthread_mutex_unlock(&philo->table->philos[ir].mutownfork);
	pthread_mutex_unlock(&philo->mutownfork);
}

void	ft_think(t_philo *philo)
{
	if (ft_timenow() - philo->leat >= philo->table->tdead)
		ft_dead(philo);
	pthread_mutex_lock(&philo->print);
	ft_printmsg(philo, 2, "is thinking");
	pthread_mutex_unlock(&philo->print);
	usleep(1000);
}

void	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->print);
	ft_printmsg(philo, 3, "is sleeping");
	pthread_mutex_unlock(&philo->print);
	usleep(philo->table->tsleep * 1000);
	if (ft_timenow() - philo->leat >= philo->table->tdead)
		ft_dead(philo);
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
