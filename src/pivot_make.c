/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_make.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:02:36 by kaara             #+#    #+#             */
/*   Updated: 2025/04/24 15:17:03 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	pivot_remake(long flag, struct s_stack *stack)
{
	int	*nums;
	int	pivot;
	int	temp_top;
	int	count;
	int	i;

	nums = nums_allocation(stack);
	i = count_pivot_u(flag, stack);
	count = i;
	temp_top = stack->top;
	i--;
	while (temp_top >= 0 && i >= 0)
	{
		nums[i] = stack->numbers[temp_top];
		i--;
		temp_top--;
	}
	heap_sort(nums, count);
	count--;
	if (count % 2)
		pivot = nums[count / 2 + 1];
	else
		pivot = nums[count / 2];
	free(nums);
	return (pivot);
}
