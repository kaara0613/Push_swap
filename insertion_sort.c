/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:18:31 by kaara             #+#    #+#             */
/*   Updated: 2024/11/19 18:01:06 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static void insertion_sort_a(struct stack *stack_a, struct stack *stack_b);
static void	sorted_rev(struct stack *stack_a, struct stack *stack_b);

void insertion_sort(struct stack *stack_a, struct stack *stack_b)
{
	insertion_sort_a(stack_a, stack_b);
	stack_flag_make(stack_a->min_value, stack_a);
	stack_flag_make(stack_b->min_value, stack_b);
	sorted_rev(stack_a, stack_b);
}

static void insertion_sort_a(struct stack *stack_a, struct stack *stack_b)
{
	if (check_sort_a(stack_a, stack_b))
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
	insertion_sort_a(stack_a, stack_b);
}

void insertion_sort_b(struct stack *stack_a, struct stack *stack_b)
{
	if (stack_b->top < 2 || stack_a->numbers[stack_a->top] == stack_b->min_value)
	{
		pb(stack_a, stack_b);
		if (stack_b->top > 0
			&& stack_b->numbers[stack_b->top] > stack_b->numbers[stack_b->top - 1]
			&& stack_b->numbers[stack_b->top] != stack_b->max_value)
			sb(stack_b);
		if (stack_b->numbers[stack_b->top] == stack_b->max_value)
			rb(stack_b);
		return ;
	}
	if (stack_a->numbers[stack_a->top] == stack_b->max_value)
	{
		pb(stack_a, stack_b);
		rb(stack_b);
		return ;
	}
	if (stack_a->numbers[stack_a->top] > stack_b->numbers[stack_b->top])
	{
		while (stack_a->numbers[stack_a->top] > stack_b->numbers[stack_b->top])
			rb(stack_b);
	}
	else
	{
		while (stack_a->numbers[stack_a->top] < stack_b->numbers[stack_b->top]){
			rrb(stack_b);}
	}
	if (stack_a->numbers[stack_a->top] < stack_b->numbers[stack_b->top]
		&& stack_a->numbers[stack_a->top] > stack_b->numbers[0])
	pb(stack_a, stack_b);
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
