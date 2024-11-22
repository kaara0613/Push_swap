/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_make.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:02:36 by kaara             #+#    #+#             */
/*   Updated: 2024/11/22 17:04:24 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pivot_make(struct stack *stack_a, struct stack *stack_b, int *nums)
{
	int	pivot;

	nums_allocation(stack_a, nums);
	pivot = pivot_remake(stack_a, nums);
	return (0);
	stack_a->min_value = pivot;
	stack_a->max_value = nums[stack_a->top];
	stack_b->min_value = 2147483647;
	stack_b->max_value = -2147483648;
	stack_flag_make(stack_a->min_value, stack_a);
	stack_flag_make(stack_b->min_value, stack_b);
	return (pivot);
}

void	stack_flag_make(int value, struct stack *stack_temp)
{
	int	i;

	i = 0;
	if (stack_temp->top < 0)
	{
		stack_temp->flag = -1;
		return ;
	}
	else
	{
		while (i <= stack_temp->top)
		{
			if (stack_temp->numbers[i] == value)
			{
				stack_temp->flag = i;
				return ;
			}
			i++;
		}
	}
}
