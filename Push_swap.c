/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:23:02 by kaara             #+#    #+#             */
/*   Updated: 2024/11/12 13:41:25 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static bool	check_sort_a(struct stack	*stack_a);
static bool	check_sort_b(struct stack	*stack_b);
static bool check_rotate(int pivot, struct stack	*stack_a, struct stack	*stack_b);
static void	push_sort_b(struct stack	*stack_a, struct stack	*stack_b);

void push_swap(int pivot, struct stack *stack_a, struct stack *stack_b)
{
	if (pivot > stack_a->numbers[stack_a->top])
    {
    	pb(stack_a, stack_b);
        push_sort_b(stack_a, stack_b);
    }
	if (stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1])
        sa(stack_a);
    if (check_rotate(pivot, stack_a, stack_b) == true)
    	return ;
    push_sort_b(stack_a, stack_b);
    push_swap(pivot, stack_a, stack_b);
}

static void	push_sort_b(struct stack	*stack_a, struct stack	*stack_b)
{
	if (stack_b->top < 1)
		return ;
    else if (stack_b->numbers[stack_b->top] < stack_b->numbers[stack_b->top - 1])
	{
        if (stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1])
        	ss(stack_a, stack_b);
        else
        	sb(stack_b);
    }
    return ;
}

static bool check_rotate(int pivot, struct stack	*stack_a, struct stack	*stack_b)
{
    bool a;
    bool b;

    a = check_sort_a(stack_a);
    b = check_sort_b(stack_b);
    if (pivot <= stack_a->numbers[stack_a->top])
    {
		if (a == false && b == false)
		{
    		rr(stack_a, stack_b);
        	return (false);
    	}
    	else if (a == false)
    	{
    		ra(stack_a);
        	return (false);
    	}
    	else if (b == false)
    	{
			rb(stack_b);
        	return (false);
    	}
    }
    else if(pivot >= stack_a->numbers[stack_a->top])
    	return (false);
    return (true);
}

static bool	check_sort_a(struct stack	*stack_a)
{
    int	i;

    i = 0;
    while (i < stack_a->top)
    {
		if(stack_a->numbers[i] < stack_a->numbers[i + 1])
        	return (false);
        i++;
    }
    return (true);
}

static bool	check_sort_b(struct stack	*stack_b)
{
    int	i;

    i = 0;
    while (i < stack_b->top)
    {
		if(stack_b->numbers[i] > stack_b->numbers[i + 1])
        	return (false);
        i++;
    }
    return (true);
}