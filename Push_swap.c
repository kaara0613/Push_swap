/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:23:02 by kaara             #+#    #+#             */
/*   Updated: 2024/11/14 23:01:56 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static void	push_sort_b(struct stack *stack_a, struct stack *stack_b);

void	push_swap(int pivot, struct stack *stack_a, struct stack *stack_b)
{
	static int i = 0;
	// printf("%d\n", i);
	// for (int i = 0; i <= stack_a->top; i++)
	// 	printf("%d", stack_a->numbers[i]);
	// printf("\n");
	// for (int i = 0; i <= stack_b->top; i++)
	// 	printf("%d", stack_b->numbers[i]);
	// printf("\n");
	i++;
	if (i == 20)
		return ;

	bool	a;

	a = check_sort_a(*stack_a);
	if (pivot <= stack_a->numbers[stack_a->top])
	{
		pb(stack_a, stack_b);//make_pivotあたりが悪さしてそう
		stack_flag_make(stack_a->max_or_min_value, stack_a);
		stack_flag_make(stack_b->max_or_min_value, stack_b);
		push_sort_b(stack_a, stack_b);
	}
	if (stack_a->numbers[stack_a->top] < stack_a->numbers[stack_a->top - 1]
		&& stack_a->flag > 2 && a == false)
	{
		sa(stack_a);
	}
	push_sort_b(stack_a, stack_b);
	if (check_rotate(pivot, stack_a, stack_b) == true)
		return ;
	push_swap(pivot, stack_a, stack_b);
}

static void	push_sort_b(struct stack *stack_a, struct stack *stack_b)
{
	bool	a;
	bool	b;

	a = check_sort_a(*stack_a);
	b = check_sort_b(*stack_b);
	if (stack_b->top < 1)
		return ;
	else if ((stack_b->flag > 2 && b == false)
		&& stack_b->numbers[stack_b->top] > stack_b->numbers[stack_b->top - 1])
	{
		if ((stack_a->flag > 2 && a == false)
			&& stack_a->numbers[stack_a->top] < stack_a->numbers[stack_a->top - 1])
			ss(stack_a, stack_b);
		else
			sb(stack_b);
	}
	return ;
}

bool	check_rotate(int pivot, struct stack *stack_a, struct stack *stack_b)
{
	bool	a;
	bool	b;

	a = check_sort_a(*stack_a);
	b = check_sort_b(*stack_b);
	if (check_pivot(stack_a) && a == true && b == true)
		return (true);
	if (pivot <= stack_a->numbers[stack_a->top])
	{
		if ((a == false && b == false) || check_pivot(stack_a))
			rr(stack_a, stack_b);
		else if (a == false || check_pivot(stack_a))
			ra(stack_a);
		else if (b == false)
			rb(stack_b);
	}
	return (false);
}
