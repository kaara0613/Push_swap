/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap_rev_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:43:06 by kaara             #+#    #+#             */
/*   Updated: 2024/11/14 22:22:35 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	rrr(struct stack *stack_a, struct stack *stack_b)
{
	stack_a = rev_rotate(stack_a);
	stack_b = rev_rotate(stack_b);
	printf("rrr\n");
}

void	rra(struct stack *stack_a)
{
	stack_a = rev_rotate(stack_a);
	printf("rra\n");
}

void	rrb(struct stack *stack_b)
{
	stack_b = rev_rotate(stack_b);
	printf("rrb\n");
}

struct stack *rev_rotate(struct stack *stack_temp)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack_temp->numbers[i];
	while (i < stack_temp->top)
	{
		stack_temp->numbers[i] = stack_temp->numbers[i + 1];
		i++;
	}
	stack_temp->numbers[stack_temp->top] = temp;
	return (stack_temp);
}

void rev_rotate_check(struct stack stack_temp)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack_temp.numbers[i];
	while (i < stack_temp.top)
	{
		stack_temp.numbers[i] = stack_temp.numbers[i + 1];
		i++;
	}
	stack_temp.numbers[stack_temp.top] = temp;
}
