/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:54:45 by kaara             #+#    #+#             */
/*   Updated: 2024/11/29 14:21:11 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// bool	check_sort_a(struct stack *stack_a)
// {
// 	int	i;

// 	i = 0;
// 	stack_flag_make(stack_a->min_value, stack_a);
// 	if (stack_a->flag == 0 && check_sort_per_a(stack_a))
// 		return (true);
// 	while (i < stack_a->flag - 1)
// 	{
// 		if (!(stack_a->numbers[i] < stack_a->numbers[i + 1]))
// 			return (false);
// 		i++;
// 	}
// 	while (stack_a->flag < stack_a->top)
// 	{
// 		if (!(stack_a->numbers[stack_a->flag] < stack_a->numbers[stack_a->flag + 1]))
// 			return (false);
// 		stack_a->flag++;
// 	}
// 	if (!(stack_a->numbers[stack_a->top] < stack_a->numbers[0]))
// 		return (false);
// 	return (true);
// }

// bool	check_sort_b(struct stack *stack_b)
// {
// 	int	i;

// 	i = 0;
// 	if (stack_b->top <= 2)
// 		return (true);
// 	stack_flag_make(stack_b->min_value, stack_b);
// 	if (stack_b->flag == 0 && check_sort_per_b(stack_b))
// 		return (true);
// 	while (i < stack_b->flag - 1)
// 	{
// 		if (!(stack_b->numbers[i] > stack_b->numbers[i + 1]))
// 			return (false);
// 		i++;
// 	}
// 	while (stack_b->flag < stack_b->top)
// 	{
// 		if (!(stack_b->numbers[stack_b->flag] > stack_b->numbers[stack_b->flag + 1]))
// 			return (false);
// 		stack_b->flag++;
// 	}
// 	if (!(stack_b->numbers[stack_b->top] > stack_b->numbers[0]))
// 		return (false);
// 	return (true);
// }

// bool	check_pivot(int pivot, struct stack *stack_a)
// {
// 	int	i;

// 	i = 0;
// 	while (i <= stack_a->top)
// 	{
// 		if (stack_a->numbers[i] < pivot)
// 			return (true);
// 		i++;
// 	}
// 	return (false);
// }

bool	check_pivot(int flag, struct nums *sort_arr, struct stack *stack_a)
{
	int	i;

	i = stack_a->top;
	while (i > -1 && stack_a->numbers[i] > stack_a->sorted_length
		&& stack_a->numbers[i] < flag)
	{
		if (stack_a->numbers[i] < sort_arr->pivot)
			return (true);
		i--;
	}
	return (false);
}

bool	check_sort(struct s_stack *stack_a)
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

bool	check_sort_per_a(struct s_stack *stack)
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
