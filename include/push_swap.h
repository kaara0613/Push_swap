/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:42:36 by kaara             #+#    #+#             */
/*   Updated: 2025/04/14 16:09:11 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>

struct s_stack
{
	int			*numbers;
	int			top;
	int			size;
	int			rev_flag;
	long int	sorted_length;
};

long			p_atoi(const char *str);
bool			sort_small_case_a(long flag,
					struct s_stack *stack_a, struct s_stack *stack_b);
bool			sort_small_case_b(long flag,
					struct s_stack *stack_a, struct s_stack *stack_b);
void			small_sort_u5(struct s_stack *stack_a, struct s_stack *stack_b);

void			small_sort_u2a(long flag,
					struct s_stack *stack_a, struct s_stack *stack_b);
void			small_sort_u2b(long flag,
					struct s_stack *stack_a, struct s_stack *stack_b);

void			cba_a2(struct s_stack *stack_a);
void			bca_a2(struct s_stack *stack_a);

void			acb_a(struct s_stack *stack_a);
void			bac_a(struct s_stack *stack_a);
void			bca_a(struct s_stack *stack_a);
void			cab_a(struct s_stack *stack_a);
void			cba_a(struct s_stack *stack_a);

//push_swap.c
void			push_swap_a(long pivot, long flag,
					struct s_stack *stack_a, struct s_stack *stack_b);

void			partition_pivot_a(long pivot, long flag,
					struct s_stack *stack_a, struct s_stack *stack_b);
void			partition_pivot_b(long pivot, long flag,
					struct s_stack *stack_a, struct s_stack *stack_b);

//check_errorcase.c
bool			check_error_case(struct s_stack *stack);
bool			check_error_args(int argc, char **argv);

//check_errorcase_u.c
bool			check_duplicate_nums(struct s_stack *stack);
bool			check_args_figure(int argc, char **argv);
bool			check_overflow(int argc, char **argv);

//count_pivot.c
int				count_pivot_u(long pivot, struct s_stack *stack);
int				count_pivot(long pivot, struct s_stack *stack);

//check_sort.c
bool			check_sort(struct s_stack *stack_a);
bool			check_pivot(long pivot, struct s_stack *stack_a);
bool			check_sort_per_a(struct s_stack *stack_a);

// pivot_make.c
int				pivot_remake(long flag, struct s_stack *stack);

// heap.c
void			heap_sort(int *nums, int n);

//stack_make.c
struct s_stack	*make_stack_a(int argc, char **argv);
struct s_stack	*make_stack_b(struct s_stack *stack_a);
int				*nums_allocation(struct s_stack *stack_a);
void			free_stack(struct s_stack *stack_a, struct s_stack *stack_b);

//stack_use.c
bool			is_empty(struct s_stack *stack_temp);
bool			is_full(struct s_stack *stack_temp);
bool			put(int input_value, struct s_stack *stack_temp);
int				pop(struct s_stack *stack_temp);

//push.c
bool			pa(struct s_stack *s_stack_a, struct s_stack *stack_b);
bool			pb(struct s_stack *s_stack_a, struct s_stack *stack_b);

//rotate.c
void			ra(struct s_stack *stack_a);
void			rb(struct s_stack *stack_b);

//rev_rotate.c
void			rra(struct s_stack *stack_a);
void			rrb(struct s_stack *stack_b);

//swap.c
void			sa(struct s_stack *s_stack_a);
void			sb(struct s_stack *s_stack_b);

//small_sort_u3
bool			abc_b(struct s_stack *stack_a, struct s_stack *stack_b);
bool			acb_b(struct s_stack *stack_a, struct s_stack *stack_b);
bool			bac_b(struct s_stack *stack_a, struct s_stack *stack_b);
bool			bca_b(struct s_stack *stack_a, struct s_stack *stack_b);
bool			cab_b(struct s_stack *stack_a, struct s_stack *stack_b);
bool			cba_b(struct s_stack *stack_a, struct s_stack *stack_b);

#endif