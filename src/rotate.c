/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:20:01 by kaara             #+#    #+#             */
/*   Updated: 2024/12/01 12:45:14 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(struct s_stack *stack_temp);

void	ra(struct s_stack *stack_a)
{
	rotate(stack_a);
	printf ("ra\n");
}

void	rb(struct s_stack *stack_b)
{
	rotate(stack_b);
	printf ("rb\n");
}

static void rotate(struct s_stack *stack_temp)
{
	int	i;
	int	temp;

	i = stack_temp->top;
	temp = stack_temp->numbers[stack_temp->top];
	while (i > 0)
	{
		stack_temp->numbers[i] = stack_temp->numbers[i - 1];
		i--;
	}
	stack_temp->numbers[0] = temp;
}
