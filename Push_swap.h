/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:42:36 by kaara             #+#    #+#             */
/*   Updated: 2024/10/28 18:59:22 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct stack {
    int *numbers;
    int top;
    int size;
};

//push_swap.c
void quick_sort(struct stack *stack_a, struct stack *stack_b);
void	partition(struct stack *stack_a, struct stack *stack_b, int pivot);

//push_swap_u.c
int head_swap(struct stack *stack_temp);
int sa(struct stack *stack_a);
// static int sb(struct stack *stack_b);
// static int ss(struct stack *stack_a, struct stack *stack_b);
int pa(struct stack *stack_a, struct stack *stack_b);
int pb(struct stack *stack_a, struct stack *stack_b);
void	rotate(struct stack *stack_temp);
void	ra(struct stack *stack_a);
// static void rb(struct stack *stack_b);
// static void rr(int *stack_a, int *stack_b);
// static void	rev_rotete(struct stack *stack_temp);
// static void rra(int *stack_a);
// static void rrb(int *stack_b);
// static void rrr(struct stack *stack_a, struct stack *stack_b);

//stack_make.c
struct stack	*make_stack_a(int	argc, char	**argv);
struct stack	*make_stack_b(struct stack	*stack_a);

//use_stack
bool is_empty(struct stack *stack_temp);
bool is_full(struct stack *stack_temp);
bool put(int	input_value, struct stack *stack_temp);
int pop(struct stack *stack_temp);

#endif