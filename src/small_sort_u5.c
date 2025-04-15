/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_u5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:52:37 by kaara             #+#    #+#             */
/*   Updated: 2025/04/15 16:52:01 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static void	case_u4(struct s_stack *stack_a, struct s_stack *stack_b);
static void	case_u5(struct s_stack *stack_a, struct s_stack *stack_b);
static int	count_pivot_under(int pivot, struct s_stack *stack);

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
	else if (stack_a->top == 3)
		case_u4(stack_a, stack_b);
	else if (stack_a->top == 4)
		case_u5(stack_a, stack_b);
}

static void	case_u4(struct s_stack *stack_a, struct s_stack *stack_b)
{
	long	pivot;

	pivot = pivot_remake(LONG_MAX, stack_a);
	while (count_pivot_under(pivot, stack_a) > 0)
	{
		if (stack_a->numbers[stack_a->top] < (int)pivot)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	if (stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1])
		sa(stack_a);
	if (stack_b->numbers[stack_b->top] < stack_b->numbers[stack_b->top - 1])
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

static void	case_u5(struct s_stack *stack_a, struct s_stack *stack_b)
{
	long	pivot;

	pivot = pivot_remake(LONG_MAX, stack_a);
	while (count_pivot_under(pivot, stack_a) > 0)
	{
		if (stack_a->numbers[stack_a->top] < pivot)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	cba_a2(stack_a);
	bca_a2(stack_a);
	acb_a2(stack_a);
	cab_a2(stack_a);
	bac_a(stack_a);
	if (stack_b->numbers[stack_b->top] < stack_b->numbers[stack_b->top - 1])
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

static int	count_pivot_under(int pivot, struct s_stack *stack)
{
	int	result;
	int	idx;

	idx = 0;
	result = 0;
	while (idx <= stack->top)
	{
		if (stack->numbers[idx] < pivot)
			result++;
		idx++;
	}
	return (result);
}
