/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:20:01 by kaara             #+#    #+#             */
/*   Updated: 2024/11/14 19:24:48 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void		ra(struct stack *stack_a);
void		rb(struct stack *stack_b);
void	rotate(struct stack *stack_temp);

void	rr(struct stack *stack_a, struct stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	printf("rr\n");
}

void	ra(struct stack *stack_a)
{
	rotate(stack_a);
	printf ("ra\n");
}

void	rb(struct stack *stack_b)
{
	rotate(stack_b);
	printf ("rb\n");
}

void	rotate(struct stack *stack_temp)
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
