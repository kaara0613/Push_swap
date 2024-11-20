/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:18:31 by kaara             #+#    #+#             */
/*   Updated: 2024/11/20 15:45:53 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void insertion_sort_a(int pivot, struct stack *stack_a, struct stack *stack_b);
static void	sorted_rev(struct stack *stack_a, struct stack *stack_b);
static void max_min_check(struct stack *stack_a, struct stack *stack_b);

void insertion_sort(int pivot, struct stack *stack_a, struct stack *stack_b)
{
	insertion_sort_a(pivot, stack_a, stack_b);
	sorted_rev(stack_a, stack_b);
}

static void insertion_sort_a(int pivot, struct stack *stack_a, struct stack *stack_b)
{
	if (check_sort_a(pivot, stack_a))
		return ;
	while ((stack_a->numbers[stack_a->top] == stack_a->min_value)
		|| (stack_a->numbers[stack_a->top] == stack_a->max_value)
		|| (stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1]))
		ra (stack_a);//rbも一緒にできる場合を実装したい
	//先にsaしてチェックしたほうがいいかも
	if(!(stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1]))
		pb(stack_a, stack_b);
	while (stack_b->numbers[stack_b->top] < stack_a->numbers[stack_a->top])//make_flagでraかrra考える
		ra(stack_a);
	pa(stack_a, stack_b);
	insertion_sort_a(pivot, stack_a, stack_b);
}

void insertion_sort_b(struct stack *stack_a, struct stack *stack_b)
{
	if (stack_b->top <= 1)
	{
		pb(stack_a, stack_b);
		if (stack_b->top == 1
			&& stack_b->numbers[stack_b->top] > stack_b->numbers[stack_b->top - 1])
			sb(stack_b);
		return ;
	}
	if ((stack_a->numbers[stack_a->top] > stack_b->max_value)
		|| (stack_a->numbers[stack_a->top] < stack_b->min_value))
		max_min_check(stack_a, stack_b);
	else if (stack_a->numbers[stack_a->top] > stack_b->numbers[stack_b->top])
	{
		while (stack_a->numbers[stack_a->top] > stack_b->numbers[stack_b->top])
			rb(stack_b);
	}
	else
	{
		while (stack_a->numbers[stack_a->top] < stack_b->numbers[stack_b->top])
			rrb(stack_b);
	}
	if (stack_a->numbers[stack_a->top] < stack_b->numbers[stack_b->top])
		pb(stack_a, stack_b);
	// if (stack_b->numbers[stack_b->top] > stack_b->numbers[stack_b->top - 1])
	// 	rb(stack_b);
	return ;
}

static void	sorted_rev(struct stack *stack_a, struct stack *stack_b)
{
	if (stack_a->top / 2 > stack_a->flag)
	{
		while (stack_a->flag-- > 0)
			rra(stack_a);
	}
	else
	{
		while (stack_a->top - stack_a->flag++ >= 0)
			ra(stack_a);
	}
	if (stack_b->top / 2 > stack_b->flag)
	{
		while (stack_b->flag-- >= 0)
			rrb(stack_b);
	}
	else
	{
		while (stack_b->top - stack_b->flag++ > 0)
			rb(stack_b);
	}
	while (stack_b->top != -1)
		pa(stack_a, stack_b);
}

static void max_min_check(struct stack *stack_a, struct stack *stack_b)
{
	if (stack_a->numbers[stack_a->top] > stack_b->max_value)
		stack_b->max_value = stack_a->numbers[stack_a->top];
	if (stack_a->numbers[stack_a->top] < stack_b->min_value)
		stack_b->min_value = stack_a->numbers[stack_a->top];
	if (stack_a->numbers[stack_a->top] > stack_b->numbers[stack_b->top])
	{
		while (stack_a->numbers[stack_a->top] > stack_b->numbers[stack_b->top]
			&& !(check_sort_per_b(stack_b)))
			rb(stack_b);
	}
	else
	{
		while (stack_a->numbers[stack_a->top] < stack_b->numbers[stack_b->top]
			&& !(check_sort_per_b(stack_b)))
			rrb(stack_b);
	}
}
