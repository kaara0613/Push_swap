/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:46:54 by kaara             #+#    #+#             */
/*   Updated: 2024/11/14 19:25:42 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static bool	head_swap(struct stack *stack_temp);
bool		sa(struct stack *stack_a);
bool		sb(struct stack *stack_b);

void	ss(struct stack *stack_a, struct stack *stack_b)
{
	head_swap(stack_a);
	head_swap(stack_b);
	printf("ss\n");
}

bool	sa(struct stack *stack_a)
{
	if (head_swap(stack_a))
	{
		printf("sa\n");
		return (true);
	}
	else
		printf("There are not enough elements in this stack to swap. (sa)\n");
	return (false);
}

bool	sb(struct stack *stack_b)
{
	if (head_swap(stack_b))
	{
		printf("sb\n");
		return (true);
	}
	else
		printf("There are not enough elements in this stack to swap. (sb)\n");
	return (false);
}

static bool	head_swap(struct stack *stack_temp)
{
	int	temp;

	if (stack_temp->top < 1)
		return (false);
	temp = stack_temp->numbers[stack_temp->top];
	stack_temp->numbers[stack_temp->top] = stack_temp->numbers[stack_temp->top - 1];
	stack_temp->numbers[stack_temp->top - 1] = temp;
	return (true);
}
