/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:54:16 by kaara             #+#    #+#             */
/*   Updated: 2025/04/14 15:54:34 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sort_small_case_a(long flag,
			struct s_stack *stack_a, struct s_stack *stack_b)
{
	if (count_pivot_u(flag, stack_a) <= 2)
	{
		small_sort_u2a(flag, stack_a, stack_b);
		return (true);
	}
	return (false);
}

bool	sort_small_case_b(long flag,
			struct s_stack *stack_a, struct s_stack *stack_b)
{
	if (count_pivot_u(flag, stack_b) <= 2)
	{
		small_sort_u2b(flag, stack_a, stack_b);
		return (true);
	}
	return (false);
}
