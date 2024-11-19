/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:23:02 by kaara             #+#    #+#             */
/*   Updated: 2024/11/18 16:29:16 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static void	push_sort_b(int pivot, struct stack *stack_a, struct stack *stack_b);
static void	check_swap(struct stack *stack_a, struct stack *stack_b);

void	push_swap(struct stack *stack_a, struct stack *stack_b)
{
	bool	a;
	bool	b;
	int		pivot;

	a = check_sort_a(stack_a, stack_b);
	b = check_sort_b(stack_b);
	if (!check_pivot(stack_a, stack_b))
	{
		if (stack_a->numbers[stack_a->top] == stack_a->min_value
			&& stack_b->numbers[stack_b->top] == stack_b->max_value)
			return ;
	}
	pivot = stack_b->min_value;
	if (stack_a->numbers[stack_a->top] >= pivot)
		push_sort_b(pivot, stack_a, stack_b);
	a = check_sort_a(stack_a, stack_b);
	b = check_sort_b(stack_b);
	if (!a || !b)
		check_swap(stack_a, stack_b);
	check_rotate(stack_a, stack_b);
	push_swap(stack_a, stack_b);
}

static void	push_sort_b(int pivot, struct stack *stack_a, struct stack *stack_b)
{
	if (stack_a->numbers[stack_a->top] >= pivot)
		pb(stack_a, stack_b);
}

void	check_rotate(struct stack *stack_a, struct stack *stack_b)
{
	bool	a;
	bool	b;
	bool	per_a;
	bool	per_b;

	if ((stack_a->numbers[stack_a->top] >= stack_b->min_value))
		return ;
	if (stack_a->numbers[stack_a->top] == stack_a->min_value
		&& stack_b->numbers[stack_b->top] == stack_b->max_value)
		return ;
	a = check_sort_a(stack_a, stack_b);
	b = check_sort_b(stack_b);
	per_a = check_sort_per_a(stack_a, stack_b);
	per_b = check_sort_per_b(stack_a);
	if ((!a) && (!b))
		rr(stack_a, stack_b);
	else if (!a)
		ra(stack_a);
	else if (!b)
		rb(stack_b);
}

void	check_swap(struct stack *stack_a, struct stack *stack_b)
{
	int a;
	int b;
	a = check_sort_a(stack_a, stack_b);//revするかしないか選択制に変更
	b = check_sort_b(stack_b);
	if ((!(stack_a->numbers[stack_a->top - 1] < stack_a->numbers[stack_a->top]) && !a)
		&& (!(stack_b->numbers[stack_b->top - 1] > stack_b->numbers[stack_b->top]) && !b))
		ss(stack_a, stack_b);
	else if (!(stack_a->numbers[stack_a->top - 1] < stack_a->numbers[stack_a->top]) && !a)
		sa(stack_a);
	else if (!(stack_b->numbers[stack_b->top - 1] > stack_b->numbers[stack_b->top]) && !b)
		sb(stack_b);
}

// void sorted(struct stack *stack_a, struct stack *stack_b)
// {
// 	if(stack_a->flag == 0)
// }

//https://push-swap-visualizer.vercel.app/