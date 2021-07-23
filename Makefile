# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/12 10:29:31 by user42            #+#    #+#              #
#    Updated: 2021/07/23 19:33:01 by ade-garr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS += ./srcs/ft_atoi.c
SRCS += ./srcs/ft_calloc.c
SRCS += ./srcs/ft_isdigit.c
SRCS += ./srcs/init.c
SRCS += ./srcs/main.c
SRCS += ./srcs/thrd_mstr.c
SRCS += ./srcs/thrd_phl.c
SRCS += ./srcs/utils.c
SRCS += ./srcs/utils2.c
SRCS += ./srcs/utils3.c

OBJS	= ${SRCS:.c=.o}

NAME	= philo

INCLUDES = ./includes/

CC		= clang

CFLAGS	+= -Wall
CFLAGS	+= -Wextra
CFLAGS	+= -Werror

HEADER = ${INCLUDES}philo.h

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -I ${INCLUDES} ${OBJS} -o ${NAME} -pthread
			printf "\033[32m$@ is ready ! \n\033[0m"

${OBJS}: %.o: %.c ${HEADER}
			${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@
			
clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
.SILENT: