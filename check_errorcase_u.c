/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errorcase_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:42:42 by kaara             #+#    #+#             */
/*   Updated: 2024/12/01 12:45:14 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_duplicate_nums(struct s_stack *stack)
{
	int	i;
	int	*nums;

	i = 0;
	nums = nums_allocation(stack);
	memcpy(nums, stack->numbers, sizeof(int) * stack->size);
	heap_sort(nums, stack->top + 1);
	while (i < stack->top)
	{
		if (nums[i] == nums[i + 1])
			return (false);
		i++;
	}
	return (true);
}