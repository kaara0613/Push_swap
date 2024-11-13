/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:23:02 by kaara             #+#    #+#             */
/*   Updated: 2024/11/13 11:02:03 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static void	push_sort_b(struct stack	*stack_a, struct stack	*stack_b);

void push_swap(int pivot, struct stack *stack_a, struct stack *stack_b)
{
    bool a;

    a = check_sort_a(*stack_a);
	if (pivot > stack_a->numbers[stack_a->top])
    {
    	pb(stack_a, stack_b);
		stack_flag_make(stack_a->max_or_min_value, stack_a);
    	stack_flag_make(stack_b->max_or_min_value, stack_b);
        push_sort_b(stack_a, stack_b);
    }
	if (a == false && stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1])
        sa(stack_a);
    push_sort_b(stack_a, stack_b);
    if (check_rotate(pivot, stack_a, stack_b) == true)
    	return ;
    push_swap(pivot, stack_a, stack_b);
}

static void	push_sort_b(struct stack	*stack_a, struct stack	*stack_b)
{
    bool a;
    bool b;

    a = check_sort_a(*stack_a);
    b = check_sort_b(*stack_b);
	if (stack_b->top < 1)
		return ;
    else if (b == false && stack_b->numbers[stack_b->top] < stack_b->numbers[stack_b->top - 1])
	{
        if (a == false && stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1])
        	ss(stack_a, stack_b);
        else
        	sb(stack_b);
    }
    return ;
}
