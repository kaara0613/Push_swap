/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_make.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:02:36 by kaara             #+#    #+#             */
/*   Updated: 2024/11/26 00:02:26 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pivot_remake(int *pivot, int *nums, struct stack *stack)
{
	int	temp_top;
	int i;

	i = count_pivot_u(stack->flag, stack) - 1;//flagをpivotに変更
	temp_top = stack->top;
	while (i >= 0)
		nums[i--] = stack->numbers[temp_top--];
	heap_sort(nums, stack->top + 1);
	if (stack->top % 2)
		*pivot = nums[stack->top / 2 + 1];
	else
		*pivot = nums[stack->top / 2];
	stack->flag = *pivot;
	return (*pivot);
}

int	return_pivot_remake(int *pivot, int *nums, struct stack *stack, struct stack *flag)
{
	int	temp_top;
	int i;

	flag->flag = *pivot;
	i = count_pivot(stack->flag, stack);//flagをpivotに変更
	temp_top = stack->top;
	while (i >= 0)
		nums[i--] = stack->numbers[temp_top--];
	heap_sort(nums, stack->top + 1);
	if (stack->top % 2)
		*pivot = nums[stack->top / 2 + 1];
	else
		*pivot = nums[stack->top / 2];
	return (*pivot);
}
// void	pivot_make(int *pivot, int *nums, struct stack *stack_a, struct stack *stack_b)
// {

// 	stack_a->flag = pivot;
// 	stack_b->flag = pivot;
// }

// void	stack_flag_make(int value, struct stack *stack_temp)
// {
// 	int	i;

// 	i = 0;
// 	if (stack_temp->top < 0)
// 	{
// 		stack_temp->flag = -1;
// 		return ;
// 	}
// 	else
// 	{
// 		while (i <= stack_temp->top)
// 		{
// 			if (stack_temp->numbers[i] == value)
// 			{
// 				stack_temp->flag = i;
// 				return ;
// 			}
// 			i++;
// 		}
// 	}
// }
