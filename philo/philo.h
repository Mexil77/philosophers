/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:00:51 by emgarcia          #+#    #+#             */
/*   Updated: 2021/10/11 18:31:57 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

typedef struct s_philo {
	size_t			able;
	size_t			index;
	size_t			ownfork;
	pthread_mutex_t	mutownfork;
	pthread_mutex_t	print;
	pthread_t		thread;
	struct s_table	*table;
	uintptr_t		leat;
}			t_philo;

typedef struct s_table {
	t_philo				*philos;
	size_t				philosize;
	struct timeval		tv;
	struct timezone		tz;
	uintptr_t			tini;
	uintptr_t			teat;
	uintptr_t			tsleep;
	uintptr_t			tdead;
}			t_table;

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
void	*ft_philo(void *phi);

void	ft_printphilos(t_philo *philos);
void	ft_printphilo(t_philo philo);

#endif