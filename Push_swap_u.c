/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:07:41 by kaara             #+#    #+#             */
/*   Updated: 2024/10/22 14:06:07 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int head_swap(struct stack *stack_temp)
{
	int temp;

    if ((stack_temp->top < 1) && (stack_temp->size < 1))
		return (0);
    temp = stack_temp->numbers[stack_temp->top];
    stack_temp->numbers[stack_temp->top] = stack_temp->numbers[stack_temp->top + 1];
	stack_temp->numbers[stack_temp->top + 1] = temp;
    return (1);
}

int sa(struct stack *stack_a)
{
	if(head_swap(stack_a))
    {
    	printf("sa\n");
        return (1);
    }
    else
		printf("There are not enough elements in this stack to swap. (sa)\n");
    return (0);
}

int sb(struct stack *stack_b)
{
	if (head_swap(stack_b))
    {
    	printf("sb\n");
        return (1);
    }
    else
		printf("There are not enough elements in this stack to swap. (sb)\n");
    return (0);
}

int ss(struct stack *stack_a, struct stack *stack_b)
{
    int i;

	i = head_swap(stack_a);
    i *= head_swap(stack_b);
	
    if (i)
    	printf("ss\n");
    else
    {
        printf ("filed ss\n");
        return (0);
    }
}

void pa(struct stack *stack_a, struct stack *stack_b)
{
	int temp;

    if (stack_b->top < 1)
	{
    	printf("This stack is void.\n");
    	return (0);
    }
    temp = pop(stack_b);
    put(temp, stack_a);
    return (1);
}

void pb(struct stack *stack_a, struct stack *stack_b)
{
	int temp;

    if (stack_a->top < 1)
	{
    	printf("This stack is void.\n");
    	return (0);
    }
    temp = pop(stack_a);
    put(temp, stack_b);
    return (1);
}

void	rotate(struct stack *stack_temp)
{
    int i;
    int temp;

    i = stack_temp->top;
    temp = stack_temp->numbers[stack_temp->top];
    while (1)
    {
        stack_temp->numbers[i] = stack_temp->numbers[i - 1];
        i--;
        if (i < 0 )
        	break ;
    }
    stack_temp->numbers[0] = temp;
}

void ra(struct stack *stack_a)
{
	rotete(stack_a);
    printf ("ra\n");
}

void rb(struct stack *stack_b)
{
	rotete(stack_b);
    printf ("rb\n");
    return (1);
}

void rr(int *stack_a, int *stack_b)
{
	rotete(stack_a);
    rotete(stack_b);
	printf("filed rr\n");
    return (1);
}

void	rev_rotete(struct stack *stack_temp)
{
    int	i;
    int	temp;

	i = 0;
    temp = stack_temp->numbers[i];
    while (1)
    {
        stack_temp->numbers[i] = stack_temp->numbers[i + 1];
        i++;
        if (i > stack_temp->top)
        	break ;
    }
    return (1);
}

void rra(int *stack_a)
{
    rev_rotete(stack_a);
    printf("rra\n");
}

void rrb(int *stack_b)
{
    rev_rotete(stack_b);
    printf("rrb\n");
}

void rrr(struct stack *stack_a, struct stack *stack_b)
{
    rev_rotete(stack_a);
    rev_rotete(stack_b);
    printf("rrr\n");
}