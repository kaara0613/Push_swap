/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:23:02 by kaara             #+#    #+#             */
/*   Updated: 2024/11/22 20:20:59 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	part_pivot_u(int pivot, struct stack *stack_a, struct stack *stack_b)
{
	if ()
	while (check_pivot(pivot, stack_a))//ここのcheckは前回のpivot以上の数が出てくるまで
	{
		if (stack_a->top < pivot)
			pb(stack_a, stack_b);
		ra(stack_a);
	}
	pivot_remake(stack_a, stack_b);//pivotの更新と前回のpivotをflagに保存
	while (check_pivot(pivot, stack_a))

	part_pivot_u(pivot, stack_a, stack_a);
}
