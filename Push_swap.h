/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:42:36 by kaara             #+#    #+#             */
/*   Updated: 2024/10/18 19:15:16 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>

struct stack {
    int *numbers;
    int top;
    int size;
};

//stack_make.c
static int	make_stack_a(int	argc, char	**argv, struct stack	stack_a);
static int	make_stack_b(struct stack	stack_a, struct stack	stack_b);

//use_stack
static void is_empty();
static void is_full();
static void put();

#endif