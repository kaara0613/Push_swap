/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:18:31 by kaara             #+#    #+#             */
/*   Updated: 2024/11/19 11:35:47 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static void insertion_sort_a(struct stack *stack_a, struct stack *stack_b);

void insertion_sort(struct stack *stack_a, struct stack *stack_b)
{
	insertion_sort_a(stack_a, stack_b);
	// insertion_sort_b(stack_a, stack_b);
}

static void insertion_sort_a(struct stack *stack_a, struct stack *stack_b)
{
	for (int i = 0; i <= stack_a->top; i++)
		printf("%d,", stack_a->numbers[i]);
	printf("%d", check_sort_a(stack_a, stack_b));
	if (check_sort_a(stack_a, stack_b))
		return ;
	if (stack_a->numbers[stack_a->top] == stack_a->min_value
		|| stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1])
		ra (stack_a);
	else if(!(stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1]))
		pb(stack_a, stack_b);
	while (1)
	{
		if (stack_b->numbers[stack_b->top] < stack_a->numbers[stack_a->top])
			break ;
		rra(stack_a);
	}
	pa(stack_a, stack_b);
	insertion_sort_a(stack_a, stack_b);
}