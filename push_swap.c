/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:23:02 by kaara             #+#    #+#             */
/*   Updated: 2024/11/28 16:24:08 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void partition_pivot_a(int *pivot, struct stack *stack_a, struct stack *stack_b);
void partition_pivot_b(int *pivot, struct stack *stack_a, struct stack *stack_b);
static void part_pivot_ub(int *pivot, int *nums, struct stack *stack_a, struct stack *stack_b);

void	part_pivot_ua(int *pivot, int *nums, struct stack *stack_a, struct stack *stack_b)
{
	static int i = 0;
	if (i++ >= 30)
		return;
	printf("a:flag:%d\n", stack_a->flag);
	// printf("%d\n",count_pivot_u(stack_a->flag, stack_a));
	if (count_pivot_u(stack_a->flag, stack_a) <= 2)
	{
		if (stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1])
			sa(stack_a);
		printf("%d", *pivot);
		while (stack_a->numbers[stack_a->top] < stack_a->flag//pivotから変更
			&& !check_sort(stack_a))
			ra(stack_a);
		printf("return a\n");
		return ;
	}
	pivot_remake(pivot, nums, stack_a);
	partition_pivot_a(pivot, stack_a, stack_b);
	part_pivot_ub(pivot, nums, stack_a, stack_b);
	pivot_remake(&stack_a->flag, nums, stack_a);
	partition_pivot_a(pivot, stack_a, stack_b);
	//returnしたタイミングのpivotをつくって仕分けまでする
	// return_pivot_remake(pivot, nums, stack_a, stack_b);
	// partition_pivot_a(pivot, stack_a, stack_b);
	// if (stack_b->top <= 1)
	// {
	// 	if (stack_b->numbers[stack_b->top] > stack_b->numbers[stack_b->top - 1])
	// 		sb(stack_b);
	// 	while (stack_b->top >= 0)
	// 	{
	// 		pa(stack_a, stack_b);
	// 		ra(stack_a);
	// 	}
	// 	pivot_reset_int_max(pivot, stack_a, stack_b);
	// }
	part_pivot_ua(pivot, nums, stack_a, stack_b);
}

void	part_pivot_ub(int *pivot, int *nums, struct stack *stack_a, struct stack *stack_b)
{
	printf("b:flag:%d\n", stack_b->flag);
	if (count_pivot_u(*pivot, stack_b) <= 2)
	{
		if (stack_b->numbers[stack_b->top] > stack_b->numbers[stack_b->top - 1])
			sb(stack_b);
		while (stack_b->numbers[stack_b->top] < *pivot)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		printf("return b\n");
		return ;
	}
	pivot_remake(pivot, nums, stack_b);
	partition_pivot_b(pivot, stack_a, stack_b);
	// part_pivot_ua(pivot, nums, stack_a, stack_b);
	// return_pivot_remake(pivot, nums, stack_b, stack_a);
	// partition_pivot_b(pivot, stack_a, stack_b);
	// if (stack_b->top <= 1)
	// {
	// 	if (stack_b->numbers[stack_b->top] > stack_b->numbers[stack_b->top - 1])
	// 		sb(stack_b);
	// 	while (stack_b->top >= 0)
	// 	{
	// 		pa(stack_a, stack_b);
	// 		ra(stack_a);
	// 	}
	// 	// pivot_reset_int_max(pivot, stack_a, stack_b);
	// }
	part_pivot_ua(pivot, nums, stack_a, stack_b);
}

void partition_pivot_a(int *pivot, struct stack *stack_a, struct stack *stack_b)
{
	int count;

	count = 1;
	while (check_pivot(*pivot, stack_a))
	{
		if (stack_a->numbers[stack_a->top] < *pivot)
			pb(stack_a, stack_b);
		else//無条件でelseしてるから無限にraする可能性がある
		{
			ra(stack_a);
			count++;
		}
	}
	while (--count > 0)
		rra(stack_a);
}

void partition_pivot_b(int *pivot, struct stack *stack_a, struct stack *stack_b)
{

	int count;

	count = 0;
	while (check_pivot(*pivot, stack_b))
	{
		if (stack_b->numbers[stack_b->top] < *pivot)
			pa(stack_a, stack_b);
		else
		{
			rb(stack_b);
			count++;
		}
	}
	while (--count > 0)
		rrb(stack_b);
}
