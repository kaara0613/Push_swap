/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:42:36 by kaara             #+#    #+#             */
/*   Updated: 2024/11/22 09:35:44 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

struct stack {
	int *numbers;
	int top;
	int size;
	int flag;//max_or_min_valueがtopから離れている距離
	int min_value;
	int max_value;
};

//push_swap.c
void	partition_pivot(int pivot, struct stack *stack_a, struct stack *stack_b);
void check_rotate(struct stack	*stack_a, struct stack	*stack_b);

//insertion_sort.c
void insertion_sort(int pivot, struct stack *stack_a, struct stack *stack_b);
void insertion_sort_b(struct stack *stack_a, struct stack *stack_b);

//check_all_sort.c
bool	check_sort_a(struct stack *stack_a);
bool	check_sort_b(struct stack	*stack_b);
bool	check_sort_per_a(struct stack *stack_a);
bool	check_sort_per_b(struct stack *stack_b);
bool	check_pivot(int pivot, struct stack *stack_a);

// make_pivot.c
int		pivot_make(struct stack	*stack_a, struct stack	*stack_b);
void	stack_flag_make(int min_value, struct stack	*stack_temp);

//stack_make.c
struct stack	*make_stack_a(int	argc, char	**argv);
struct stack	*make_stack_b(struct stack	*stack_a);
bool	free_stack(struct stack *stack_a, struct stack *stack_b);

//stack_use.c
bool is_empty(struct stack *stack_temp);
bool is_full(struct stack *stack_temp);
bool put(int	input_value, struct stack *stack_temp);
int pop(struct stack *stack_temp);

//push.c
bool pa(struct stack *stack_a, struct stack *stack_b);
bool pb(struct stack *stack_a, struct stack *stack_b);

//rotate.c
void ra(struct stack *stack_a);
void rb(struct stack *stack_b);
void rr(struct stack *stack_a, struct stack *stack_b);
void    rotate(struct stack *stack_temp);

//rev_rotate.c
void rra(struct stack *stack_a);
void rrb(struct stack *stack_b);
void rrr(struct stack *stack_a, struct stack *stack_b);
void    rev_rotate(struct stack *stack_temp);

//swap.c
void sa(struct stack *stack_a);
void sb(struct stack *stack_b);
void ss(struct stack *stack_a, struct stack *stack_b);

// static void	sorted_rev(struct stack *stack_a, struct stack *stack_b);
#endif