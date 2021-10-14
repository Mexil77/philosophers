# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 18:31:58 by emgarcia          #+#    #+#              #
#    Updated: 2021/10/13 22:51:30 by emgarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_fork.c ft_philo.c ft_aux.c ft_libft.c main.c
OBJS	=	${SRCS:.c=.o}
NAME	=	philo
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
