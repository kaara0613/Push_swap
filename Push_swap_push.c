/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:24:34 by kaara             #+#    #+#             */
/*   Updated: 2024/11/14 19:17:38 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

bool	pa(struct stack *stack_a, struct stack *stack_b)
{
	int	temp;

	if (stack_b->top < 0)
	{
		printf("This bstack is void.\n");
		return (false);
	}
	temp = pop(stack_b);
	if (temp == -1)
	{
		printf("filed pop\n");
		return (false);
	}
	put(temp, stack_a);
	printf("pa");
	return (true);
}

bool	pb(struct stack *stack_a, struct stack *stack_b)
{
	int	temp;

	if (stack_a->top < 0)
	{
		printf("This astack is void.\n");
		return (false);
	}
	temp = pop(stack_a);
	if (temp == -1)
	{
		printf("filed pop\n");
		return (false);
	}
	put(temp, stack_b);
	printf("pb\n");
	return (true);
}
