/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:23:02 by kaara             #+#    #+#             */
/*   Updated: 2024/11/26 16:41:59 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void partition_pivot_a(int *pivot, struct stack *stack_a, struct stack *stack_b);
void partition_pivot_b(int *pivot, struct stack *stack_a, struct stack *stack_b);
static void part_pivot_ub(int *pivot, int *nums, struct stack *stack_a, struct stack *stack_b);

void	part_pivot_ua(int *pivot, int *nums, struct stack *stack_a, struct stack *stack_b)
{
	printf("a\n");
	// printf("%d\n",count_pivot_u(stack_a->flag, stack_a));
	if (count_pivot_u(stack_a->flag, stack_a) <= 2)
	{
		if (stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1])
			sa(stack_a);
		while (stack_a->numbers[stack_a->top] < *pivot
			&& !check_sort(stack_a))
			ra(stack_a);
		return ;
	}
	pivot_remake(pivot, nums, stack_a);
	partition_pivot_a(pivot, stack_a, stack_b);
	part_pivot_ub(pivot, nums, stack_a, stack_b);
	//returnしたタイミングのpivotをつくって仕分けまでする
	printf("return a\n");
	return_pivot_remake(pivot, nums, stack_a, stack_b);
	partition_pivot_a(pivot, stack_a, stack_b);
	part_pivot_ua(pivot, nums, stack_a, stack_b);
}

void	part_pivot_ub(int *pivot, int *nums, struct stack *stack_a, struct stack *stack_b)
{
	printf("b\n");
	if (count_pivot_u(stack_b->flag, stack_b) <= 2)
	{
		if (stack_b->numbers[stack_b->top] > stack_b->numbers[stack_b->top - 1])
			sb(stack_b);
		while (stack_b->numbers[stack_b->top] < *pivot)
			pa(stack_a, stack_b);
		return ;
	}
	pivot_remake(pivot, nums, stack_b);
	partition_pivot_b(pivot, stack_a, stack_b);
	part_pivot_ua(pivot, nums, stack_a, stack_b);
	printf("return b\n");
	return_pivot_remake(pivot, nums, stack_b, stack_a);
	printf("%d\n", *pivot);
	partition_pivot_b(pivot, stack_a, stack_b);
	part_pivot_ua(pivot, nums, stack_a, stack_b);
}

void partition_pivot_a(int *pivot, struct stack *stack_a, struct stack *stack_b)
{
	while (check_pivot(*pivot, stack_a))
	{
		if (stack_a->numbers[stack_a->top] < *pivot)
			pb(stack_a, stack_b);

		else
			ra(stack_a);
	}
}

void partition_pivot_b(int *pivot, struct stack *stack_a, struct stack *stack_b)
{
	while (check_pivot(*pivot, stack_b))
	{
		if (stack_b->numbers[stack_b->top] < *pivot)
			pa(stack_a, stack_b);
		else
			rb(stack_b);
	}
}
