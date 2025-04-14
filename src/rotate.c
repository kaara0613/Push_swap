/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:20:01 by kaara             #+#    #+#             */
/*   Updated: 2025/04/14 15:51:53 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static void	rotate(struct s_stack *stack_temp);

void	ra(struct s_stack *stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(struct s_stack *stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

static void	rotate(struct s_stack *stack_temp)
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
