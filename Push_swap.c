/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:23:02 by kaara             #+#    #+#             */
/*   Updated: 2024/11/16 09:39:53 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static void	push_sort_b(int pivot, struct stack *stack_a, struct stack *stack_b);
static void	check_swap(int pivot, struct stack *stack_a, struct stack *stack_b);

void	push_swap(int pivot, struct stack *stack_a, struct stack *stack_b)
{
		static int i = 0;
	for (int i = 0; i <= stack_a->top; i++)
		printf("%d", stack_a->numbers[i]);
	printf("\n");
	for (int i = 0; i <= stack_b->top; i++)
		printf("%d", stack_b->numbers[i]);
	printf("\n");
	i++;
	if (i >=20)
		return ;
	bool	a;
	bool	b;

	if (stack_a->numbers[stack_a->top] >= pivot)
		push_sort_b(pivot, stack_a, stack_b);
	a = check_sort_a(*stack_a);//kokonokanouseigatakai
	b = check_sort_b(*stack_b);
	// printf("%d\n%d\n", a, b);
	if(!a || !b)
	{
		check_swap(pivot, stack_a, stack_b);
		if(stack_a->numbers[stack_a->top] >= pivot)
			push_swap(pivot, stack_a, stack_b);
	}
	if (check_rotate(stack_a, stack_b))
		return ;
	push_swap(pivot, stack_a, stack_b);
}

static void	push_sort_b(int pivot, struct stack *stack_a, struct stack *stack_b)
{
	if (stack_a->numbers[stack_a->top] >= pivot)
	{
		pb(stack_a, stack_b);
		stack_flag_make(stack_a->max_or_min_value, stack_a);
		stack_flag_make(stack_b->max_or_min_value, stack_b);
	}
}

bool	check_rotate(struct stack *stack_a, struct stack *stack_b)
{
	bool	a;
	bool	b;

	a = check_sort_a(*stack_a);
	b = check_sort_b(*stack_b);
    printf("%d\n", a);
    printf("%d\n", b);
	if (!check_pivot(stack_a) && a == true && b == true)
		return (true);
	else if (b == false && (a == false || check_pivot(stack_a)))
		rr(stack_a, stack_b);
	else if (a == false || check_pivot(stack_a))
		ra(stack_a);
	else if (b == false)
		rb(stack_b);
	return (false);
}

static void	check_swap(int pivot, struct stack *stack_a, struct stack *stack_b)
{
	if (stack_b->top < 2)
	{
		if (stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1] || stack_a->numbers[stack_a->top - 1] >= pivot)
			sa(stack_a);
		return ;
	}
	if (stack_a->numbers[stack_a->top - 1] > stack_a->numbers[stack_a->top]
		&& stack_b->numbers[stack_b->top - 1] < stack_b->numbers[stack_b->top])
		ss(stack_a, stack_b);
	else if (stack_a->numbers[stack_a->top - 1] > stack_a->numbers[stack_a->top])
		sa(stack_a);
	else if (stack_b->numbers[stack_b->top - 1] < stack_b->numbers[stack_b->top])
		sb(stack_b);
}
