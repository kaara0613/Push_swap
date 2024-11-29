/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:23:02 by kaara             #+#    #+#             */
/*   Updated: 2024/11/29 15:41:45 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void part_pivot_ub(struct nums *sort_arr, struct stack *stack_a, struct stack *stack_b);
void partition_pivot_a(int flag, struct nums *sort_arr, struct stack *stack_a, struct stack *stack_b);
void partition_pivot_b(int flag, struct nums *sort_arr, struct stack *stack_a, struct stack *stack_b);
void return_partition_pivot_a(int flag, struct nums *sort_arr, struct stack *stack_a, struct stack *stack_b);

void	part_pivot_ua(struct nums *sort_arr, struct stack *stack_a, struct stack *stack_b)
{
	int a_flag;
		printf("a\n");
	a_flag = sort_arr->pivot;
	if (count_pivot_u(sort_arr->pivot, stack_a) <= 2)
	{
		if (stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1])
			sa(stack_a);
		while (stack_a->numbers[stack_a->top] < sort_arr->pivot//pivotから変更
			&& !check_sort(stack_a))
		{
			ra(stack_a);
			stack_a->sorted_length = stack_a->numbers[0];
		}
		return ;
	}
	pivot_remake(a_flag, sort_arr, stack_a);
	partition_pivot_a(a_flag, sort_arr, stack_a, stack_b);
	part_pivot_ub(sort_arr, stack_a, stack_b);
	part_pivot_ua(sort_arr, stack_a, stack_b);
	// pivot_remake(a_flag, sort_arr, stack_a);
	// partition_pivot_a(a_flag, sort_arr, stack_a, stack_b);
	// part_pivot_ua(sort_arr, stack_a, stack_b);
	// part_pivot_ub(sort_arr, stack_a, stack_b);
	// return_partition_pivot_a(a_flag, sort_arr, stack_a, stack_b);
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
}

void	part_pivot_ub(struct nums *sort_arr, struct stack *stack_a, struct stack *stack_b)
{
	int b_flag;
	printf("b\n");
	b_flag = sort_arr->pivot;
	if (count_pivot_u(sort_arr->pivot, stack_b) <= 2)
	{
		if (stack_b->numbers[stack_b->top] > stack_b->numbers[stack_b->top - 1])
			sb(stack_b);
		while (stack_b->numbers[stack_b->top] < sort_arr->pivot)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
			stack_a->sorted_length = stack_a->numbers[0];
		}
		return ;
	}
	pivot_remake(b_flag, sort_arr, stack_b);
	partition_pivot_b(b_flag, sort_arr, stack_a, stack_b);
	part_pivot_ua(sort_arr, stack_a, stack_b);
	pivot_remake(b_flag, sort_arr, stack_b);
	partition_pivot_b(b_flag, sort_arr, stack_a, stack_b);
	part_pivot_ub(sort_arr, stack_a, stack_b);
	// part_pivot_ua(sort_arr, stack_a, stack_b);
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
}

void partition_pivot_a(int flag, struct nums *sort_arr, struct stack *stack_a, struct stack *stack_b)
{
	int count;

	count = 1;
	while (check_pivot(flag, sort_arr, stack_a))//下にソートずみのpivot以下がくっついてる時にエラー
	{
		if (stack_a->numbers[stack_a->top] < sort_arr->pivot)
			pb(stack_a, stack_b);
		else
		{
			ra(stack_a);
			count++;
		}
	}
	if (flag != 2147483647)
	{
		while (--count > 0)
			rra(stack_a);
	}
}

void partition_pivot_b(int flag, struct nums *sort_arr, struct stack *stack_a, struct stack *stack_b)
{
	int count;

	count = 1;
	while (check_pivot(flag, sort_arr, stack_b))
	{
		if (stack_b->numbers[stack_b->top] < sort_arr->pivot)
			pa(stack_a, stack_b);
		else
		{
			rb(stack_b);
			count++;
		}
	}
	if (flag != 2147483647)//常に真なんかいい方法ないか？
	{
		while (--count > 0)
			rrb(stack_b);
	}
}

void return_partition_pivot_a(int flag, struct nums *sort_arr, struct stack *stack_a, struct stack *stack_b)
{
	int count;

	count = 1;
	printf("%ld", stack_a->sorted_length);
	while (check_pivot(flag, sort_arr, stack_a))
	{
		if (stack_a->numbers[stack_a->top] < sort_arr->pivot)
			pb(stack_a, stack_b);
		else// if (stack_a->numbers[stack_a->top] > sort_arr->pivot
		// 	&& stack_a->numbers[stack_a->top] < flag)//無条件でelseしてるから無限にraする可能性がある
		{
			ra(stack_a);
			count++;
		}
	}
	while (--count > 0)
		rra(stack_a);
}