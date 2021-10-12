/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:57:57 by emgarcia          #+#    #+#             */
/*   Updated: 2021/10/12 19:17:48 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_printmsg(t_philo *philo, size_t color, char *msg)
{
	long	t;

	t = ft_timenow() - philo->table->tini;
	if (color == 0)
		printf(CYAN "[ %zu ] philo[%zu] %s\n" RESET, t, philo->index, msg);
	if (color == 1)
		printf(YELLOW "[ %zu ] philo[%zu] %s\n" RESET, t, philo->index, msg);
	if (color == 2)
		printf(GREEN "[ %zu ] philo[%zu] %s\n" RESET, t, philo->index, msg);
	if (color == 3)
		printf(MAGENTA "[ %zu ] philo[%zu] %s\n" RESET, t, philo->index, msg);
	if (color == 4)
		printf(RED "[ %zu ] philo[%zu] %s\n" RESET, t, philo->index, msg);
}

long	ft_timenow(void)
{
	struct timeval		tv;
	struct timezone		tz;

	gettimeofday(&tv, &tz);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
