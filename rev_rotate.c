/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:43:06 by kaara             #+#    #+#             */
/*   Updated: 2024/12/01 10:20:58 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rev_rotate(struct stack *stack_temp);

void	rra(struct stack *stack_a)
{
	rev_rotate(stack_a);
	printf("rra\n");
}

void	rrb(struct stack *stack_b)
{
	rev_rotate(stack_b);
	printf("rrb\n");
}

static void rev_rotate(struct stack *stack_temp)
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
}
