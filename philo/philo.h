/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:00:51 by emgarcia          #+#    #+#             */
/*   Updated: 2021/10/05 21:37:56 by emgarcia         ###   ########.fr       */
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
	size_t	forkl;
	size_t	forkr;
}			t_philo;

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);

#endif