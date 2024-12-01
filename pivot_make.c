/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_make.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:02:36 by kaara             #+#    #+#             */
/*   Updated: 2024/12/01 10:27:11 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pivot_remake(int flag, struct stack *stack)
{
	int *nums;
	int pivot;
	int	temp_top;
	int count;
	int i;

	nums = nums_allocation(stack);
	i = count_pivot_u(flag, stack) - 1;//flagをpivotに変更
	count = i;
	temp_top = stack->top;
	while (i >= 0)
		nums[i--] = stack->numbers[temp_top--];
	heap_sort(nums, count + 1);
	if (count % 2)
		pivot = nums[count / 2 + 1];
	else
		pivot = nums[count / 2];
	free(nums);
	return (pivot);
}
