/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:46:54 by kaara             #+#    #+#             */
/*   Updated: 2024/12/01 14:18:49 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static struct s_stack	*head_swap(struct s_stack *stack_temp);

void	sa(struct s_stack *stack_a)
{
	stack_a = head_swap(stack_a);
	printf("sa\n");
}

void	sb(struct s_stack *stack_b)
{
	stack_b = head_swap(stack_b);
	printf("sb\n");
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
