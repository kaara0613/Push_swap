/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:23:02 by kaara             #+#    #+#             */
/*   Updated: 2024/11/25 23:56:27 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void partition_pivot_a(int *pivot, struct stack *stack_a, struct stack *stack_b);
void partition_pivot_b(int *pivot, struct stack *stack_a, struct stack *stack_b);
static void part_pivot_ub(int *pivot, int *nums, struct stack *stack_a, struct stack *stack_b);

void	part_pivot_ua(int *pivot, int *nums, struct stack *stack_a, struct stack *stack_b)
{
	printf("a\n");
	if (count_pivot_u(*pivot, stack_a) <= 2) //前回のflag以下の要素が2つ以下ならsaしてreturn;
	{
		if (stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1])
			sa(stack_a);
		while (stack_a->numbers[stack_a->top] < *pivot
			&& !check_sort(stack_a))//raの条件に未完全ソートを追加
			ra(stack_a);
		return ;
	}
	*pivot = pivot_remake(pivot, nums, stack_a);//pivotの更新と前回のpivotをflagに保存
	partition_pivot_a(pivot, stack_a, stack_b);
	part_pivot_ub(pivot, nums, stack_a, stack_b);
	// printf("a_before:%d\n", pivot);
	// pivot = return_pivot_remake(pivot, nums, stack_a, stack_b);
	// printf("a_after:%d\n", pivot);
	// partition_pivot_a(pivot, stack_a, stack_b);
	part_pivot_ua(pivot, nums, stack_a, stack_b);
}

void	part_pivot_ub(int *pivot, int *nums, struct stack *stack_a, struct stack *stack_b)
{
	printf("b\n");
	if (count_pivot_u(*pivot, stack_b) <= 2) //前回のflag以下の要素が2つ以下ならsaしてreturn;
	{
		if (stack_b->numbers[stack_b->top] > stack_b->numbers[stack_b->top - 1])
			sb(stack_b);
		return ;
		while (stack_b->numbers[stack_b->top] < *pivot)//returnのタイミングで無限ループ
			pa(stack_a, stack_b);
		// 	ra(stack_a);
		// }
		return ;
	}
	*pivot = pivot_remake(pivot, nums, stack_b);//pivotの更新と前回のpivotをflagに保存
	partition_pivot_b(pivot, stack_a, stack_b);
	part_pivot_ua(pivot, nums, stack_a, stack_b);
	// printf("b_before:%d\n", pivot);
	// pivot = return_pivot_remake(pivot, nums, stack_b, stack_a);
	// printf("b_after:%d\n", pivot);
	// partition_pivot_b(pivot, stack_a, stack_b);
	part_pivot_ub(pivot, nums, stack_a, stack_b);
}

void partition_pivot_a(int *pivot, struct stack *stack_a, struct stack *stack_b)
{
	while (check_pivot(*pivot, stack_a)) //ここのcheckは前回のpivot以上の数が出てくるまで
	{
		if (stack_a->numbers[stack_a->top] < *pivot)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
}

void partition_pivot_b(int *pivot, struct stack *stack_a, struct stack *stack_b)
{
	while (check_pivot(*pivot, stack_b))//ここのcheckは前回のpivot以上の数が出てくるまで
	{
		if (stack_b->numbers[stack_b->top] < *pivot)
			pa(stack_a, stack_b);
		else
			rb(stack_b);
	}
}
