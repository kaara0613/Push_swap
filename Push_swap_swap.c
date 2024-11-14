/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:46:54 by kaara             #+#    #+#             */
/*   Updated: 2024/11/14 21:44:35 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static struct stack	*head_swap(struct stack *stack_temp);

void	ss(struct stack *stack_a, struct stack *stack_b)
{
	stack_a = head_swap(stack_a);
	stack_b = head_swap(stack_b);
	printf("ss\n");
}

void	sa(struct stack *stack_a)
{
	stack_a = head_swap(stack_a);
	printf("sa\n");
}

void	sb(struct stack *stack_b)
{
	stack_b = head_swap(stack_b);
	printf("sb\n");
}

static struct stack	*head_swap(struct stack *stack_temp)
{
	int	temp;

	if (stack_temp->top < 1)
		return (NULL);
	temp = stack_temp->numbers[stack_temp->top];
	stack_temp->numbers[stack_temp->top] = stack_temp->numbers[stack_temp->top - 1];
	stack_temp->numbers[stack_temp->top - 1] = temp;
	return (stack_temp);
}
