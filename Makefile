# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 15:46:31 by kaara             #+#    #+#              #
#    Updated: 2024/12/02 14:43:19 by kaara            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = src/main.c \
       src/check_errorcase.c \
	   src/check_errorcase_u.c \
       src/stack_make.c \
	   src/stack_use.c \
       src/pivot_make.c \
	   src/count_pivot.c \
	   src/heap_sort.c \
       src/push_swap.c \
	   src/push_swap_u.c \
       src/check_sort.c \
       src/push.c \
	   src/rotate.c \
	   src/rev_rotate.c \
	   src/swap.c \
	   src/p_atoi.c \
	   src/sort_small_array.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -Iinclude

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -Iinclude $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

-include $(OBJS:.o=.d)

clean:
	rm -f $(OBJS) $(OBJS:.o=.d)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
