/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_pivot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:10:17 by kaara             #+#    #+#             */
/*   Updated: 2025/04/23 20:38:53 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_pivot_u(long flag, struct s_stack *stack)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack->top;
	while (stack->numbers[temp] >= stack->sorted_length
		&& stack->numbers[temp--] < flag && temp > -1)
		i++;
	return (i);
}

int	count_pivot(long flag, struct s_stack *stack)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack->top;
	while (temp-- >= 0 && stack->numbers[temp] >= flag)
		i++;
	return (i);
}
