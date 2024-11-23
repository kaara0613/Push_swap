/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_make.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:02:36 by kaara             #+#    #+#             */
/*   Updated: 2024/11/23 10:44:06 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pivot_make(int *nums, struct stack *stack_a, struct stack *stack_b)
{
	int	pivot;

	nums_allocation(nums, stack_a);
	pivot = 2147483647;
	stack_a->flag = pivot;
	stack_b->flag = pivot;
	return (pivot);
}

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
