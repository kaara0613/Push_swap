/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_use.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:08:39 by kaara             #+#    #+#             */
/*   Updated: 2025/04/15 16:50:37 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include <limits.h>

bool	is_empty(struct s_stack *stack_temp)
{
	if (stack_temp->top == -1)
		return (true);
	return (false);
}

bool	is_full(struct s_stack *stack_temp)
{
	if (stack_temp->top == stack_temp->size - 1)
		return (true);
	return (false);
}

bool	put(int input_value, struct s_stack *stack_temp)
{
	if (is_full(stack_temp))
	{
		// ft_printf("This stack is full.");
		return (false);
	}
	stack_temp->numbers[stack_temp->top + 1] = input_value;
	stack_temp->top++;
	return (true);
}

long	pop(struct s_stack *stack_temp)
{
	long	return_value;

	if (is_empty(stack_temp))
	{
		// ft_printf("This stack is empty");
		return (LONG_MIN);
	}
	return_value = stack_temp->numbers[stack_temp->top];
	stack_temp->numbers[stack_temp->top] = 0;
	stack_temp->top -= 1;
	return (return_value);
}
