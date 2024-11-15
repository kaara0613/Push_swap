/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:02:36 by kaara             #+#    #+#             */
/*   Updated: 2024/11/15 19:48:05 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	pivot_make(struct stack *stack_a, struct stack *stack_b)
{
	int	pivot;

	pivot = 5;
	stack_a->max_or_min_value = 1;
	stack_b->max_or_min_value = pivot;
	stack_flag_make(stack_a->max_or_min_value, stack_a);
	stack_flag_make(stack_b->max_or_min_value, stack_b);
	return (pivot);
}

void	stack_flag_make(int value, struct stack *stack_temp)
{
	int	i;

	i = 0;
	if (stack_temp->top < 0 || stack_temp->numbers[stack_temp->top] == value)
	{
		stack_temp->flag = -1;
		return ;
	}
	else
	while (i <= stack_temp->top)
	{
		if (stack_temp->numbers[i] == value)
		{
			stack_temp->flag = i + 1;
			return ;
		}
		i++;
	}
}

