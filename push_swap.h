/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:42:36 by kaara             #+#    #+#             */
/*   Updated: 2024/12/02 13:08:39 by kaara            ###   ########.fr       */
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
#include <limits.h>
#include "../libft/libft.h"

struct s_stack {
	int			*numbers;
	int			top;
	int			size;
	int			rev_flag;
	long int	sorted_length;
};

typedef	struct s_stack	t_stack;

//push_swap.c
void	push_swap_a(int pivot, int flag, t_stack *stack_a, t_stack *stack_b);

void	partition_pivot_a(int pivot, int flag, t_stack *stack_a, t_stack *stack_b);
void	partition_pivot_b(int pivot, int flag, t_stack *stack_a, t_stack *stack_b);

//check_errorcase.c
bool	check_error_case(t_stack *stack);
bool	check_error_args(int argc, char **argv);

//check_errorcase_u.c
bool	check_duplicate_nums(t_stack *stack);
bool check_args_figure(int argc, char **argv);
bool check_overflow(int argc, char **argv);


//count_pivot.c
int		count_pivot_u(int pivot, t_stack *stack);
int		count_pivot(int pivot, t_stack *stack);

//check_sort.c
bool	check_sort(t_stack *stack_a);
bool	check_pivot(int pivot, t_stack *stack_a);
bool	check_sort_per_a(t_stack *stack_a);

// pivot_make.c
int		pivot_remake(int flag, t_stack *stack);

// heap.c
void	heap_sort(int *nums, int n);

//stack_make.c
t_stack	*make_stack_a(int argc, char **argv);
t_stack	*make_stack_b(t_stack *stack_a);
int				*nums_allocation(t_stack *stack_a);
void			free_stack(t_stack *stack_a, t_stack *stack_b);

//stack_use.c
bool	is_empty(t_stack *stack_temp);
bool	is_full(t_stack *stack_temp);
bool	put(int input_value, t_stack *stack_temp);
int		pop(t_stack *stack_temp);

//push.c
bool	pa(t_stack *s_stack_a, t_stack *stack_b);
bool	pb(t_stack *s_stack_a, t_stack *stack_b);

//rotate.c
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);

//rev_rotate.c
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);

//swap.c
void	sa(t_stack *s_stack_a);
void	sb(t_stack *s_stack_b);

#endif