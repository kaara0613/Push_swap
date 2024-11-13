/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:24:34 by kaara             #+#    #+#             */
/*   Updated: 2024/11/12 20:43:53 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

bool pa(struct stack *stack_a, struct stack *stack_b)
{
	int temp;

    if (stack_b->top < 0)
	{
    	printf("This stack is void.\n");
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

bool pb(struct stack *stack_a, struct stack *stack_b)
{
	int temp;

    if (stack_a->top < 0)
	{
    	printf("This stack is void.\n");
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
