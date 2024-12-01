# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 15:46:31 by kaara             #+#    #+#              #
#    Updated: 2024/12/01 11:15:10 by kaara            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Push_swap.a

SRCS = main.c\
		check_errorcase.c check_errorcase_u.c\
		stack_make.c stack_use.c\
		pivot_make.c count_pivot.c heap_sort.c\
		push_swap.c push_swap_u.c\
		check_sort.c\
		push.c rotate.c rev_rotate.c swap.c\

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS = -Wall -Wextra -Werror -g

AR = ar rcs
RM = rm -f

TEST00=unit_test/unit_test00.c
# TEST00_OBJ = ${TEST00:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

test:all
	$(CC) $(CFLAGS) $(TEST00) $(NAME)
	

re: fclean all


.PHONY: all clean fclean re test
