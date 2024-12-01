/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:54:45 by kaara             #+#    #+#             */
/*   Updated: 2024/12/01 11:38:49 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_pivot(int pivot, struct stack *stack_a)
{
	int	i;

	i = 0;
	while (i <= stack_a->top)
	{
		if (stack_a->numbers[i] < pivot)
			return (true);
		i++;
	}
	return (false);
}

bool	check_sort(struct stack *stack_a)
{
	int	i;

	i = 0;
	while (i < stack_a->top)
	{
		if (!(stack_a->numbers[i] > stack_a->numbers[i + 1]))
			return (false);
		i++;
	}
	return (true);
}

bool	check_sort_per_a(struct stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (!(stack->numbers[i] > stack->numbers[i + 1]))
			return (false);
		i++;
	}
	return (true);
}
