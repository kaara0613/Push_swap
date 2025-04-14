/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:46:54 by kaara             #+#    #+#             */
/*   Updated: 2025/04/14 16:14:02 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include <stdlib.h>

static struct s_stack	*head_swap(struct s_stack *stack_temp);

void	sa(struct s_stack *stack_a)
{
	stack_a = head_swap(stack_a);
	ft_printf("sa\n");
}

void	sb(struct s_stack *stack_b)
{
	stack_b = head_swap(stack_b);
	ft_printf("sb\n");
}

static struct s_stack	*head_swap(struct s_stack *stack_temp)
{
	int	temp;

	if (stack_temp->top < 1)
		return (NULL);
	temp = stack_temp->numbers[stack_temp->top];
	stack_temp->numbers[stack_temp->top]
		= stack_temp->numbers[stack_temp->top - 1];
	stack_temp->numbers[stack_temp->top - 1] = temp;
	return (stack_temp);
}
