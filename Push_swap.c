/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:23:02 by kaara             #+#    #+#             */
/*   Updated: 2024/11/17 18:04:28 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static void	push_sort_b(int pivot, struct stack *stack_a, struct stack *stack_b);
static void	check_swap(struct stack *stack_a, struct stack *stack_b);

void	push_swap(int depth, struct stack *stack_a, struct stack *stack_b)
{
	static int i = 0;
	i++;
	if (i >= 60)
		return ;
	// for (int i = 0; i <= stack_a->top; i++)
	// 	printf("%d,", stack_a->numbers[i]);
	// printf("\n");
	// for (int i = 0; i <= stack_b->top; i++)
	// 	printf("%d,", stack_b->numbers[i]);

	// // printf("%d\n%d\n", a1, b1);
	// 		printf("\n");
	// printf("\n");

	bool	a;
	bool	b;
	int		pivot;

	if (depth <= 0)
		return ;
	a = check_sort_a(stack_a, stack_b);
	b = check_sort_b(stack_b);
	if (a && b)
		return (push_swap(--depth, stack_a, stack_b));
	pivot = stack_b->max_or_min_value;
	if (stack_a->numbers[stack_a->top] >= pivot)
		push_sort_b(pivot, stack_a, stack_b);
	a = check_sort_a(stack_a, stack_b);
	b = check_sort_b(stack_b);
	if (!a || !b)
	{
		check_swap(stack_a, stack_b);
		// if (stack_a->numbers[stack_a->top] >= pivot)
		// {
		// 	push_swap(stack_a, stack_b);
		// 	return (push_swap(stack_a, stack_b));
		// }
	}
	check_rotate(stack_a, stack_b);
	push_swap(++depth, stack_a, stack_b);
}

static void	push_sort_b(int pivot, struct stack *stack_a, struct stack *stack_b)
{
	if (stack_a->numbers[stack_a->top] >= pivot)
	{
		pb(stack_a, stack_b);
	}
}

void	check_rotate(struct stack *stack_a, struct stack *stack_b)
{
	bool	a;
	bool	b;

	if ((stack_a->numbers[stack_a->top] >= stack_b->max_or_min_value))
		return ;
	a = check_sort_a(stack_a, stack_b);
	b = check_sort_b(stack_b);
	if (!b && !a)//revしない方の条件式も追加
		rr(stack_a, stack_b);
	else if (!a)
		ra(stack_a);
	else if (!b)
		rb(stack_b);
}

void	check_swap(struct stack *stack_a, struct stack *stack_b)
{
	int a;
	int b;
	a = check_sort_a(stack_a, stack_b);//revするかしないか選択制に変更
	b = check_sort_b(stack_b);
	if (!a && !b && stack_a->numbers[stack_a->top - 1] > stack_a->numbers[stack_a->top]
		&& stack_b->numbers[stack_b->top - 1] > stack_b->numbers[stack_b->top])
		ss(stack_a, stack_b);
	else if (!a && stack_a->numbers[stack_a->top - 1] > stack_a->numbers[stack_a->top])
		sa(stack_a);
	else if (!b && stack_b->numbers[stack_b->top - 1] > stack_b->numbers[stack_b->top])
		sb(stack_b);
}

// void sorted(struct stack *stack_a, struct stack *stack_b)
// {
// 	if(stack_a->flag == 0)
// }

//https://push-swap-visualizer.vercel.app/