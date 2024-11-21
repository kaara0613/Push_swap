/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:23:02 by kaara             #+#    #+#             */
/*   Updated: 2024/11/21 19:11:08 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	check_swap(struct stack *stack_a, struct stack *stack_b);

void	partition_pivot(int pivot, struct stack *stack_a, struct stack *stack_b)
{
	static int i = 0;
	if (i++ >= 50)
		return;
	if (check_pivot(pivot, stack_a))
		return ;
	if (stack_a->numbers[stack_a->top] < pivot)
		insertion_sort_b(stack_a, stack_b);
	if (!(stack_a->numbers[stack_a->top - 1] < stack_a->numbers[stack_a->top])
		&& !(stack_a->numbers[stack_a->top] < pivot))
		sa(stack_a);
	else if(!(stack_a->numbers[stack_a->top] < pivot))
		ra(stack_a);
	partition_pivot(pivot, stack_a, stack_b);
}

// void	check_rotate(struct stack *stack_a, struct stack *stack_b)
// {
// 	bool	a;
// 	bool	b;

// 	if ((stack_a->numbers[stack_a->top] >= stack_b->min_value))
// 		return ;
// 	if (stack_a->numbers[stack_a->top] == stack_a->min_value
// 		&& stack_b->numbers[stack_b->top] == stack_b->max_value)
// 		return ;
// 	a = check_sort_a(stack_a, stack_b);
// 	b = check_sort_b(stack_b);
// 	if ((!a) && (!b))
// 		rr(stack_a, stack_b);
// 	else if (!a)
// 		ra(stack_a);
// 	else if (!b)
// 		rb(stack_b);
// }

// void	check_swap(struct stack *stack_a, struct stack *stack_b)
// {
// 	int a;
// 	int b;
// 	a = check_sort_a(stack_a, stack_b);//revするかしないか選択制に変更
// 	b = check_sort_b(stack_b);
// 	if ((!(stack_a->numbers[stack_a->top - 1] < stack_a->numbers[stack_a->top]) && !a)
// 		&& (!(stack_b->numbers[stack_b->top - 1] > stack_b->numbers[stack_b->top]) && !b))
// 		ss(stack_a, stack_b);
// 	else if (!(stack_a->numbers[stack_a->top - 1] < stack_a->numbers[stack_a->top]) && !a)
// 		sa(stack_a);
// 	else if (!(stack_b->numbers[stack_b->top - 1] > stack_b->numbers[stack_b->top]) && !b)
// 		sb(stack_b);
// }

// void sorted(struct stack *stack_a, struct stack *stack_b)
// {
// 	if(stack_a->flag == 0)
// }

//https://push-swap-visualizer.vercel.app/