/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:00:51 by emgarcia          #+#    #+#             */
/*   Updated: 2021/10/13 17:38:25 by emgarcia         ###   ########.fr       */
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
	size_t			index;
	size_t			eatens;
	pthread_mutex_t	mutownfork;
	pthread_t		thread;
	struct s_table	*table;
	long			leat;
}			t_philo;

typedef struct s_table {
	pthread_mutex_t	print;
	t_philo			*philos;
	size_t			philosize;
	size_t			musteat;
	size_t			died;
	long			tini;
	long			teat;
	long			tsleep;
	long			tdead;
}			t_table;

int		ft_atoi(const char *str);
void	*ft_philo(void *phi);
long	ft_timenow(void);
void	ft_printmsg(t_philo *philo, size_t color, char *msg);
void	ft_getforks(t_philo *philo, size_t	ir);
size_t	ft_alleaten(t_philo	*philo);
void	ft_unlockforks(t_table *table);
void	ft_dead(t_philo *philo);
void	ft_usleep(long time);

#endif