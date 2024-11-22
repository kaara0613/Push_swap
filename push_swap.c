/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:23:02 by kaara             #+#    #+#             */
/*   Updated: 2024/11/22 12:36:27 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition_pivot(int pivot, struct stack *stack_a, struct stack *stack_b)
{
	if (!check_pivot(pivot, stack_a))
		return ;
	if (stack_a->numbers[stack_a->top] < pivot)
		insertion_sort_b(stack_a, stack_b);
	if (!(stack_a->numbers[stack_a->top - 1] < stack_a->numbers[stack_a->top])
		&& !(stack_a->numbers[stack_a->top] < pivot))
		sa(stack_a);
	else if(!(stack_a->numbers[stack_a->top] < pivot))
		ra(stack_a);
	partition_pivot(pivot, stack_a, stack_b);
}
