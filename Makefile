# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 15:46:31 by kaara             #+#    #+#              #
#    Updated: 2024/11/12 19:49:33 by kaara            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Push_swap.a

SRCS = Push_swap.c stack_make.c stack_use.c Push_swap_push.c Push_swap_rotate.c Push_swap_swap.c make_pivot.c check_all_sort.c Push_swap_rev_rotate.c

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re