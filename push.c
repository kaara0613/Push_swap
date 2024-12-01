/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:24:34 by kaara             #+#    #+#             */
/*   Updated: 2024/12/01 12:45:14 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	pa(struct s_stack *stack_a, struct s_stack *stack_b)
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
	printf("pa\n");
	return (true);
}

bool	pb(struct s_stack *stack_a, struct s_stack *stack_b)
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
