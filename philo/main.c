/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:59:29 by emgarcia          #+#    #+#             */
/*   Updated: 2021/10/05 22:14:32 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*slowprint(void *arg)
{
	char	*msg;
	size_t	i;

	msg = (char *)arg;
	i = -1;
	while (++i < ft_strlen(msg))
	{
		printf(" %c", msg[i]);
		fflush(stdout);
		usleep(1000000);
	}
	printf("\n");
	return (NULL);
}

int	main(void)
{
	pthread_t	h1;
	pthread_t	h2;

	pthread_create(&h1, NULL, slowprint, "Hola");
	pthread_join(h1, NULL);
	pthread_create(&h2, NULL, slowprint, "mundo");
	pthread_join(h2, NULL);
	printf("FIN main\n");
}

/* int	main(int argc, char const *argv[])
{
	size_t	i;
	t_philo	*philos;

	if (argc)
		printf("%s\n", argv[0]);
	philos = malloc(sizeof(t_philo) * (ft_atoi(argv[1]) + 1));
	philos[ft_atoi(argv[1])].able = 0;
	i = -1;
	while (++i < ft_atoi(argv[1]))
		ft_iniphilo(philos[i]);
	return (0);
} */
