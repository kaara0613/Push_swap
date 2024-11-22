/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:18:31 by kaara             #+#    #+#             */
/*   Updated: 2024/11/22 10:55:52 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_num_rot_a(struct stack *stack_a, struct stack *stack_b);
static void	check_num_rot_b(struct stack *stack_a, struct stack *stack_b);
static void insertion_sort_a(int pivot, struct stack *stack_a, struct stack *stack_b);
static void	sorted_rev(struct stack *stack_a, struct stack *stack_b);
static void max_min_value_a(struct stack *stack_a);
static void max_min_value(struct stack *stack_a, struct stack *stack_b);

void insertion_sort(int pivot, struct stack *stack_a, struct stack *stack_b)
{
	insertion_sort_a(pivot, stack_a, stack_b);
	sorted_rev(stack_a, stack_b);
}

static void insertion_sort_a(int pivot, struct stack *stack_a, struct stack *stack_b)
{
	int num_rot;

	static int i = 0;
	if (i++ >= 60)
		return ;

	if (check_sort_a(stack_a))
		return ;
	while (stack_a->numbers[stack_a->top] < stack_a->numbers[stack_a->top - 1]
		|| stack_a->numbers[stack_a->top] == stack_a->min_value)
		ra(stack_a);
	if (stack_a->numbers[stack_a->top] == stack_a->max_value)
		max_min_value_a(stack_a);
	if (stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1])
		pb(stack_a, stack_b);
	num_rot = check_num_rot_a(stack_a, stack_b);
	if (num_rot < 0)
	{
		while (num_rot++ < 0)
			rra(stack_b);
	}
	else
	{
		while (num_rot-- > 0)
			ra(stack_b);
	}
	pa(stack_a, stack_b);
	insertion_sort_a(pivot, stack_a, stack_b);
}

void insertion_sort_b(struct stack *stack_a, struct stack *stack_b)
{
	if (stack_b->top < 1)
	{
		pb(stack_a, stack_b);
		if (stack_b->numbers[stack_b->top] > stack_b->max_value)
			stack_b->max_value = stack_b->numbers[stack_b->top];
		if (stack_b->numbers[stack_b->top] < stack_b->min_value)
			stack_b->min_value = stack_b->numbers[stack_b->top];
		if (stack_b->top >= 1
			&& stack_b->numbers[stack_b->top] < stack_b->numbers[stack_b->top - 1])
			sb(stack_b);
		return ;
	}
	if ((stack_a->numbers[stack_a->top] > stack_b->max_value)
		|| (stack_a->numbers[stack_a->top] < stack_b->min_value))
	{
		max_min_value(stack_a, stack_b);
		return ;
	}
	check_num_rot_b(stack_a, stack_b);
	pb(stack_a, stack_b);
}
static void max_min_value_a(struct stack *stack_a)
{
	stack_flag_make(stack_a->min_value, stack_a);
	if (stack_a->top / 2 > stack_a->flag)
	{
		while (stack_a->flag-- >= 0)
			rra(stack_a);
	}
	else
	{
		while (stack_a->top - stack_a->flag++ > 0)
			ra(stack_a);
	}
}

static void max_min_value(struct stack *stack_a, struct stack *stack_b)
{
	stack_flag_make(stack_b->max_value, stack_b);
	if (stack_a->numbers[stack_a->top] > stack_b->max_value)
		stack_b->max_value = stack_a->numbers[stack_a->top];
	else if (stack_a->numbers[stack_a->top] < stack_b->min_value)
		stack_b->min_value = stack_a->numbers[stack_a->top];
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
	pb(stack_a, stack_b);
	if (stack_b->numbers[stack_b->top] == stack_b->min_value)
		rb(stack_b);
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
		while (stack_b->flag-- > 0)
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

static int check_num_rot_a(struct stack *stack_a, struct stack *stack_b)
{
	int num_rot;
	int temp;

	num_rot = 0;
	while (stack_b->numbers[stack_b->top] > stack_a->numbers[stack_a->top]) //&& stack_a->numbers[stack_a->top] < stack_a->numbers[0])
	{
		rotate(stack_a);
		temp = num_rot++;
	}
	while (temp-- >= 0)
		rev_rotate(stack_a);
	if (num_rot > stack_a->top / 2)
		num_rot = 0 - ((stack_a->top + 1) - num_rot);
	return (num_rot);
}

static void	check_num_rot_b(struct stack *stack_a, struct stack *stack_b)
{
	int num_rot;
	int temp;

	num_rot = 0;
	while (stack_a->numbers[stack_a->top] < stack_b->numbers[stack_b->top]
		|| stack_a->numbers[stack_a->top] > stack_b->numbers[0])
	{
		rotate(stack_b);
		temp = num_rot++;
	}
	while (temp-- >= 0)
		rev_rotate(stack_b);
	if (num_rot > stack_b->top / 2)
		num_rot = 0 - ((stack_b->top + 1) - num_rot);
	if (num_rot < 0)
	{
		while (num_rot++ < 0)
			rrb(stack_b);
	}
	else
	{
		while (num_rot-- > 0)
			rb(stack_b);
		// if (stack_a->top / 2)
		// 	rb(stack_b);
	}
}
