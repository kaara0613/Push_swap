/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:42:36 by kaara             #+#    #+#             */
/*   Updated: 2024/12/01 11:16:00 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>


struct stack {
	int *numbers;
	int top;
	int size;
	long int sorted_length;
	int rev_flag;
};

//push_swap.c
void	push_swap_a(int pivot, int flag, struct stack *stack_a, struct stack *stack_b);

//check_errorcase.c
bool	check_error_case(struct stack *stack);

//check_errorcase_u.c
bool	check_Duplicate_nums(struct stack *stack);

//count_pivot.c
int count_pivot_u(int pivot, struct stack *stack);
int count_pivot(int pivot, struct stack *stack);

//check_sort.c
bool	check_sort(struct stack *stack_a);
bool	check_pivot(int pivot, struct stack *stack_a);
bool	check_sort_per_a(struct stack *stack_a);

// pivot_make.c
int	pivot_remake(int flag, struct stack *stack);

// heap.c
void	heap_sort(int *nums, int n);

//stack_make.c
struct stack	*make_stack_a(int	argc, char	**argv);
struct stack	*make_stack_b(struct stack	*stack_a);
int	*nums_allocation(struct stack *stack_a);
void	free_stack(struct stack *stack_a, struct stack *stack_b);

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

//rev_rotate.c
void rra(struct stack *stack_a);
void rrb(struct stack *stack_b);

//swap.c
void sa(struct stack *stack_a);
void sb(struct stack *stack_b);

#endif