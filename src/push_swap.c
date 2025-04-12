/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:23:02 by kaara             #+#    #+#             */
/*   Updated: 2024/12/02 20:28:13 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap_b(long pivot, long flag, struct s_stack *stack_a, struct s_stack *stack_b);

void	push_swap_a(long pivot, long flag, struct s_stack *stack_a, struct s_stack *stack_b)
{
	long	flag_temp;

	if (sort_small_case_a(flag, stack_a, stack_b))
		return ;
	flag_temp = flag;
	flag = pivot;
	pivot = pivot_remake(flag_temp, stack_a);
	partition_pivot_a(pivot, flag, stack_a, stack_b);
	push_swap_b(pivot, flag, stack_a, stack_b);
	push_swap_a(flag, flag_temp, stack_a, stack_b);
}

static void	push_swap_b(long pivot, long flag, struct s_stack *stack_a, struct s_stack *stack_b)
{
	long	flag_temp;

	if (sort_small_case_b(flag, stack_a, stack_b))
		return ;
	flag_temp = flag;
	flag = pivot;
	pivot = pivot_remake(flag_temp, stack_b);
	partition_pivot_b(pivot, flag, stack_a, stack_b);
	push_swap_a(pivot, flag, stack_a, stack_b);
	push_swap_b(flag, flag_temp, stack_a, stack_b);
}
