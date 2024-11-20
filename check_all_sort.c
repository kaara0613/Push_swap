/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:54:45 by kaara             #+#    #+#             */
/*   Updated: 2024/11/20 11:38:29 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_sort_a(struct stack *stack_a, struct stack *stack_b)
{
	int	i;

	i = 0;
	stack_flag_make(stack_a->min_value, stack_a);
	if (check_pivot(stack_a, stack_b))
		return (false);
	if (stack_a->flag == 0 && check_sort_per_a(stack_a, stack_b))
		return (true);
	while (i < stack_a->flag - 1)
	{
		if (!(stack_a->numbers[i] < stack_a->numbers[i + 1]))
			return (false);
		i++;
	}
	while (stack_a->flag < stack_a->top)
	{
		if (!(stack_a->numbers[stack_a->flag] < stack_a->numbers[stack_a->flag + 1]))
			return (false);
		stack_a->flag++;
	}
	if (!(stack_a->numbers[stack_a->top] < stack_a->numbers[0]))
		return (false);
	return (true);
}

bool	check_sort_b(struct stack *stack_b)
{
	int	i;

	i = 0;
	if (stack_b->top <= 2)
		return (true);
	stack_flag_make(stack_b->min_value, stack_b);
	if (stack_b->flag == 0 && check_sort_per_b(stack_b))
		return (true);
	while (i < stack_b->flag - 1)
	{
		if (!(stack_b->numbers[i] > stack_b->numbers[i + 1]))
			return (false);
		i++;
	}
	while (stack_b->flag < stack_b->top)
	{
		if (!(stack_b->numbers[stack_b->flag] > stack_b->numbers[stack_b->flag + 1]))
			return (false);
		stack_b->flag++;
	}
	if (!(stack_b->numbers[stack_b->top] > stack_b->numbers[0]))
		return (false);
	return (true);
}

bool	check_pivot(struct stack *stack_a, struct stack *stack_b)
{
	int	i;

	i = 0;
	while (i <= stack_a->top)
	{
		if (stack_a->numbers[i] >= stack_b->min_value)
			return (true);
		i++;
	}
	return (false);
}

bool	check_sort_per_a(struct stack *stack_a, struct stack *stack_b)
{
	int	i;

	i = 0;
	stack_flag_make(stack_a->min_value, stack_a);
	if (check_pivot(stack_a, stack_b))
		return (false);
	while (i < stack_a->top)
	{
		if (!(stack_a->numbers[i] < stack_a->numbers[i + 1]))
			return (false);
		i++;
	}
	return (true);
}

bool	check_sort_per_b(struct stack *stack_b)
{
	int	i;

	i = 0;
	stack_flag_make(stack_b->min_value, stack_b);
	while (i < stack_b->top)
	{
		if (!(stack_b->numbers[i] > stack_b->numbers[i + 1]))
			return (false);
		i++;
	}
	return (true);
}
