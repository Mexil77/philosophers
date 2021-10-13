/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:00:21 by emgarcia          #+#    #+#             */
/*   Updated: 2021/10/13 06:54:51 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_forkright(t_philo *philo, size_t	ir)
{
	pthread_mutex_lock(&philo->table->philos[ir].mutownfork);
	pthread_mutex_lock(&philo->table->philos[ir].print);
	ft_printmsg(philo, 0, "has taken a fork");
	pthread_mutex_unlock(&philo->table->philos[ir].print);
	if (philo->table->philosize == 1)
	{
		ft_dead(philo);
		return ;
	}
	pthread_mutex_lock(&philo->mutownfork);
	pthread_mutex_lock(&philo->print);
	ft_printmsg(philo, 0, "has taken a fork");
	pthread_mutex_unlock(&philo->print);
}

void	ft_forkleft(t_philo *philo, size_t ir)
{
	pthread_mutex_lock(&philo->mutownfork);
	pthread_mutex_lock(&philo->print);
	ft_printmsg(philo, 0, "has taken a fork");
	pthread_mutex_unlock(&philo->print);
	pthread_mutex_lock(&philo->table->philos[ir].mutownfork);
	pthread_mutex_lock(&philo->table->philos[ir].print);
	ft_printmsg(philo, 0, "has taken a fork");
	pthread_mutex_unlock(&philo->table->philos[ir].print);
}
