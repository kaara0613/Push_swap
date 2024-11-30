/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:23:02 by kaara             #+#    #+#             */
/*   Updated: 2024/11/30 14:57:23 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void partition_pivot_a(int pivot, int flag, struct stack *stack_a, struct stack *stack_b);
void partition_pivot_b(int pivot, int flag, struct stack *stack_a, struct stack *stack_b);
static void push_swap_b(int pivot, int flag, struct stack *stack_a, struct stack *stack_b);

void	push_swap_a(int pivot, int flag, struct stack *stack_a, struct stack *stack_b)
{
	int flag_temp;

	if (count_pivot_u(flag, stack_a) <= 2)
	{
		if (stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1])
			sa(stack_a);
		while (stack_a->numbers[stack_a->top] < flag
			&& stack_a->numbers[stack_a->top] > stack_a->sorted_length)
			ra(stack_a);
		stack_a->sorted_length = stack_a->numbers[0];
		return ;
	}
	flag_temp = flag;
	flag = pivot;
	pivot = pivot_remake(flag_temp, stack_a);
	partition_pivot_a(pivot, flag, stack_a, stack_b);
	push_swap_b(pivot, flag, stack_a, stack_b);
	push_swap_a(flag, flag_temp, stack_a, stack_b);
}

static void	push_swap_b(int pivot, int flag, struct stack *stack_a, struct stack *stack_b)
{
	int flag_temp;
	if (count_pivot_u(flag, stack_b) <= 2)
	{
		if (stack_b->numbers[stack_b->top] > stack_b->numbers[stack_b->top - 1])
			sb(stack_b);
		while (stack_b->top > -1 && stack_b->numbers[stack_b->top] < flag)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		stack_a->sorted_length = stack_a->numbers[0];
		return ;
	}
	flag_temp = flag;
	flag = pivot;
	pivot = pivot_remake(flag_temp, stack_b);
	partition_pivot_b(pivot, flag, stack_a, stack_b);
	push_swap_a(pivot, flag, stack_a, stack_b);
	push_swap_b(flag, flag_temp, stack_a, stack_b);
}

void partition_pivot_a(int pivot, int flag, struct stack *stack_a, struct stack *stack_b)
{
	int count;

	count = 0;
	while (stack_a->numbers[stack_a->top] < flag && check_pivot(pivot, stack_a)
		&& stack_a->numbers[stack_a->top] > stack_a->sorted_length)
	{
		if (stack_a->numbers[stack_a->top] < pivot)
			pb(stack_a, stack_b);
		else//無条件でelseしてるから無限にraする可能性がある
		{
			ra(stack_a);
			count++;
		}
	}
	if (stack_a->rev_flag == 0)
	{
		stack_a->rev_flag = 1;
		return ;
	}
	while (count-- > 0)
		rra(stack_a);
}

void partition_pivot_b(int pivot, int flag, struct stack *stack_a, struct stack *stack_b)
{

	int count;

	count = 0;
	while (stack_b->numbers[stack_b->top] < flag && check_pivot(pivot, stack_b))
	{
		if (stack_b->numbers[stack_b->top] < pivot)
			pa(stack_a, stack_b);
		else
		{
			rb(stack_b);
			count++;
		}
	}
	if (stack_b->rev_flag == 0)
	{
		stack_b->rev_flag = 1;
		return ;
	}
	while (count-- > 0)
		rrb(stack_b);
}

// void sort_before_return_a(int pivot, int flag, struct stack *stack_a)
// {
// 	if (stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1])
// 		sa(stack_a);
// 	ra(stack_a);
// 	if (stack_a->numbers[stack_a->top - 1] > stack_a->numbers[stack_a->top - 2])
// 		ra()
// }