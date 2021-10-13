/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:41:47 by emgarcia          #+#    #+#             */
/*   Updated: 2021/10/13 17:32:03 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_dead(t_philo *philo)
{
	ft_printmsg(philo, 4, "is dead");
	philo->table->died++;
	ft_unlockforks(philo->table);
}

void	ft_eat(t_philo *philo)
{
	size_t	ir;

	if (philo->table->died)
		return ;
	ir = philo->index;
	if (ir == philo->table->philosize)
		ir = 0;
	ft_getforks(philo, ir);
	if (ft_timenow() - philo->leat + philo->table->teat > philo->table->tdead)
	{
		ft_dead(philo);
		return ;
	}
	ft_printmsg(philo, 1, "is eating");
	ft_usleep(philo->table->teat);
	philo->eatens++;
	philo->leat = ft_timenow();
	pthread_mutex_unlock(&philo->table->philos[ir].mutownfork);
	pthread_mutex_unlock(&philo->mutownfork);
}

void	ft_think(t_philo *philo)
{
	if (philo->table->died)
		return ;
	if (ft_timenow() - philo->leat >= philo->table->tdead)
	{
		ft_dead(philo);
		return ;
	}
	ft_printmsg(philo, 2, "is thinking");
}

void	ft_sleep(t_philo *philo)
{
	if (philo->table->died)
		return ;
	ft_printmsg(philo, 3, "is sleeping");
	ft_usleep(philo->table->tsleep);
	if (ft_timenow() - philo->leat >= philo->table->tdead)
	{
		ft_dead(philo);
		return ;
	}
}

void	*ft_philo(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	if (philo->index % 2 == 0)
		usleep(100);
	while (1)
	{
		ft_eat(philo);
		if ((philo->table->musteat && ft_alleaten(philo)) || philo->table->died)
			break ;
		ft_sleep(philo);
		if ((philo->table->musteat && ft_alleaten(philo)) || philo->table->died)
			break ;
		ft_think(philo);
		if ((philo->table->musteat && ft_alleaten(philo)) || philo->table->died)
			break ;
		if (philo->table->died)
			break ;
	}
	pthread_join(philo->thread, NULL);
	return (NULL);
}
