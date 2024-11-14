/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_use.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:08:39 by kaara             #+#    #+#             */
/*   Updated: 2024/11/14 13:20:24 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

bool	is_empty(struct stack *stack_temp)
{
	if (stack_temp->top == -1)
		return (true);
	return (false);
}

bool	is_full(struct stack *stack_temp)
{
	if (stack_temp->top == stack_temp->size - 1)
		return (true);
	return (false);
}

bool	put(int input_value, struct stack *stack_temp)
{
	if (is_full(stack_temp))
	{
		printf("This stack is full.");
		return (false);
	}
	stack_temp->numbers[stack_temp->top + 1] = input_value;
	stack_temp->top++;
	return (true);
}

int	pop(struct stack *stack_temp)
{
	int	return_value;

	if (is_empty(stack_temp))
	{
		printf("This stack is empty");
		return (-1);
	}
	return_value = stack_temp->numbers[stack_temp->top];
	stack_temp->numbers[stack_temp->top] = 0;
	stack_temp->top -= 1;
	return (return_value);
}
