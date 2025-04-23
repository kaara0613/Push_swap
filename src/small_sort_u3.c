/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_u3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:21:43 by kaara             #+#    #+#             */
/*   Updated: 2025/04/23 20:40:47 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cba_a2(struct s_stack *stack_a)
{
	if (stack_a->top == 2
		&& stack_a->numbers[stack_a->top - 1] < stack_a->numbers[stack_a->top]
		&& stack_a->numbers[stack_a->top - 1]
		> stack_a->numbers[stack_a->top - 2])
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	bca_a2(struct s_stack *stack_a)
{
	if (stack_a->top == 2
		&& stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 2]
		&& stack_a->numbers[stack_a->top] < stack_a->numbers[stack_a->top - 1])
		rra(stack_a);
}

void	acb_a2(struct s_stack *stack_a)
{
	if (stack_a->top == 2
		&& stack_a->numbers[stack_a->top - 2] > stack_a->numbers[stack_a->top]
		&& stack_a->numbers[stack_a->top - 2]
		< stack_a->numbers[stack_a->top - 1])
	{
		rra(stack_a);
		sa(stack_a);
	}
}

void	cab_a2(struct s_stack *stack_a)
{
	if (stack_a->top == 2
		&& stack_a->numbers[stack_a->top - 2] < stack_a->numbers[stack_a->top]
		&& stack_a->numbers[stack_a->top - 2]
		> stack_a->numbers[stack_a->top - 1])
		ra(stack_a);
}

void	bac_a(struct s_stack *stack_a)
{
	if (stack_a->top == 2
		&& stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1]
		&& stack_a->numbers[stack_a->top] < stack_a->numbers[stack_a->top - 2])
		sa(stack_a);
}
