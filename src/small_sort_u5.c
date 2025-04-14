/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_u5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:52:37 by kaara             #+#    #+#             */
/*   Updated: 2025/04/14 16:21:40 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort_u5(struct s_stack *stack_a, struct s_stack *stack_b)
{
	if (stack_a->top == 1)
	{
		if (stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1])
			sa(stack_a);
	}
	else if (stack_a->top == 2)
	{
		cba_a2(stack_a);
		bca_a2(stack_a);
		acb_a2(stack_a);
		cab_a2(stack_a);
		bac_a(stack_a);
	}
	else if (stack_a->top <= 4)
		(void)stack_b;
}
