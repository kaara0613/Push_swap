/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:23:02 by kaara             #+#    #+#             */
/*   Updated: 2024/11/23 13:19:46 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void part_pivot_ub(int pivot, int *nums, struct stack *stack_a, struct stack *stack_b);

void	part_pivot_ua(int pivot, int *nums, struct stack *stack_a, struct stack *stack_b)
{
	// static int i = 0;
	// if (i >= 10)
	// 	return ;
	if (count_flag_u(stack_a) <= 2)//前回のflag以下の要素が2つ以下ならsaしてreturn;
	{
		if (stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1])
			sa(stack_a);
		while (stack_a->numbers[stack_a->top] < stack_a->flag
			&& !check_sort(stack_a))//raの条件に未完全ソートを追加
			ra(stack_a);
		return ;
	}
	pivot = pivot_remake(pivot, nums, stack_a);//pivotの更新と前回のpivotをflagに保存
	while (check_pivot(pivot, stack_a))//ここのcheckは前回のpivot以上の数が出てくるまで
	{
		if (stack_a->numbers[stack_a->top] < pivot)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	part_pivot_ub(pivot, nums, stack_a, stack_b);
}

void	part_pivot_ub(int pivot, int *nums, struct stack *stack_a, struct stack *stack_b)
{
	if (count_flag_u(stack_b) <= 2)//前回のflag以下の要素が2つ以下ならsaしてreturn;
	{
		if (stack_b->numbers[stack_b->top] < stack_b->numbers[stack_b->top - 1])
			sb(stack_b);
		while (stack_a->numbers[stack_a->top] < stack_a->flag)
		{
			pa(stack_a, stack_b);
			if (!check_sort(stack_a))//raの条件に未完全ソートを追加
				ra(stack_b);
		}
		return ;
	}
	pivot = pivot_remake(pivot, nums, stack_b);//pivotの更新と前回のpivotをflagに保存
	while (check_pivot(pivot, stack_b))//ここのcheckは前回のpivot以上の数が出てくるまで
	{
		if (stack_b->numbers[stack_b->top] < pivot)
			pa(stack_a, stack_b);
		else
			rb(stack_b);
	}
	part_pivot_ua(pivot, nums, stack_a, stack_b);
}
