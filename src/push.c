/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:24:34 by kaara             #+#    #+#             */
/*   Updated: 2025/04/15 16:51:30 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include <limits.h>

bool	pa(struct s_stack *stack_a, struct s_stack *stack_b)
{
	long	temp;

	if (stack_b->top < 0)
	{
		// ft_printf("This bstack is void.\n");
		return (false);
	}
	temp = pop(stack_b);
	if (temp == LONG_MIN)
	{
		// ft_printf("filed pop\n");
		return (false);
	}
	put(temp, stack_a);
	ft_printf("pa\n");
	return (true);
}

bool	pb(struct s_stack *stack_a, struct s_stack *stack_b)
{
	long	temp;

	if (stack_a->top < 0)
	{
		// ft_printf("This astack is void.\n");
		return (false);
	}
	temp = pop(stack_a);
	if (temp == LONG_MIN)
	{
		// ft_printf("filed pop\n");
		return (false);
	}
	put(temp, stack_b);
	ft_printf("pb\n");
	return (true);
}
