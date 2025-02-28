/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 08:53:21 by kaara             #+#    #+#             */
/*   Updated: 2024/12/01 12:45:14 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void partition_pivot_a(int pivot, int flag, t_stack *stack_a, t_stack *stack_b)
{
	int	count;

	count = 0;
	while (stack_a->numbers[stack_a->top] < flag && check_pivot(pivot, stack_a)
		&& stack_a->numbers[stack_a->top] > stack_a->sorted_length)
	{
		if (stack_a->numbers[stack_a->top] < pivot)
			pb(stack_a, stack_b);
		else
		{
			ra(stack_a);
			count++;
		}
	}
	if (stack_a->rev_flag == 0)
	{
		stack_a->rev_flag = 1;
		return ;
	}
	while (count-- > 0)
		rra(stack_a);
}

void partition_pivot_b(int pivot, int flag, t_stack *stack_a, t_stack *stack_b)
{
	int	count;

	count = 0;
	while (stack_b->numbers[stack_b->top] < flag && check_pivot(pivot, stack_b))
	{
		if (stack_b->numbers[stack_b->top] < pivot)
			pa(stack_a, stack_b);
		else
		{
			rb(stack_b);
			count++;
		}
	}
	if (stack_b->rev_flag == 0)
	{
		stack_b->rev_flag = 1;
		return ;
	}
	while (count-- > 0)
		rrb(stack_b);
}