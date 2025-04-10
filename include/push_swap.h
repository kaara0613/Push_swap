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

struct s_stack {
	int			*numbers;
	int			top;
	int			size;
	int			rev_flag;
	long int	sorted_length;
};

long	p_atoi(const char *str);
int* coordinate_compression(int *arr, int elements_nbr);
bool	sort_small_case_a(long flag, struct s_stack *stack_a);
bool	sort_small_case_b(long flag, struct s_stack *stack_a, struct s_stack *stack_b);

//push_swap.c
void	push_swap_a(long pivot, long flag, struct s_stack *stack_a, struct s_stack *stack_b);

void	partition_pivot_a(long pivot, long flag, struct s_stack *stack_a, struct s_stack *stack_b);
void	partition_pivot_b(long pivot, long flag, struct s_stack *stack_a, struct s_stack *stack_b);

//check_errorcase.c
bool	check_error_case(struct s_stack *stack);
bool	check_error_args(int argc, char **argv);

//check_errorcase_u.c
bool	check_duplicate_nums(struct s_stack *stack);
bool check_args_figure(int argc, char **argv);
bool check_overflow(int argc, char **argv);


//count_pivot.c
int		count_pivot_u(long pivot, struct s_stack *stack);
int		count_pivot(long pivot, struct s_stack *stack);

//check_sort.c
bool	check_sort(struct s_stack *stack_a);
bool	check_pivot(long pivot, struct s_stack *stack_a);
bool	check_sort_per_a(struct s_stack *stack_a);

// pivot_make.c
int		pivot_remake(long flag, struct s_stack *stack);

// heap.c
void	heap_sort(int *nums, int n);

//stack_make.c
struct s_stack	*make_stack_a(int argc, char **argv);
struct s_stack	*make_stack_b(struct s_stack *stack_a);
int				*nums_allocation(struct s_stack *stack_a);
void			free_stack(struct s_stack *stack_a, struct s_stack *stack_b);

//stack_use.c
bool	is_empty(struct s_stack *stack_temp);
bool	is_full(struct s_stack *stack_temp);
bool	put(int input_value, struct s_stack *stack_temp);
int		pop(struct s_stack *stack_temp);

//push.c
bool	pa(struct s_stack *s_stack_a, struct s_stack *stack_b);
bool	pb(struct s_stack *s_stack_a, struct s_stack *stack_b);

//rotate.c
void	ra(struct s_stack *stack_a);
void	rb(struct s_stack *stack_b);

//rev_rotate.c
void	rra(struct s_stack *stack_a);
void	rrb(struct s_stack *stack_b);

//swap.c
void	sa(struct s_stack *s_stack_a);
void	sb(struct s_stack *s_stack_b);

#endif