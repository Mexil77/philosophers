/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:00:51 by emgarcia          #+#    #+#             */
/*   Updated: 2021/10/06 21:49:46 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_philo {
	size_t	able;
	size_t	index;
	size_t	ownfork;
	size_t	forkl;
	size_t	forkr;
}			t_philo;

typedef struct s_table {
	t_philo			*philos;
	size_t			philosize;
	pthread_mutex_t	printmutex;
}			t_table;

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
void	*ft_philo(void *phi);

void	ft_printphilos(t_philo *philos);
void	ft_printphilo(t_philo philo);

#endif