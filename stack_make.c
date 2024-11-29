/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_make.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:34:32 by kaara             #+#    #+#             */
/*   Updated: 2024/11/29 12:27:42 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct stack	*make_stack_a(int argc, char **argv)
{
	int				count;
	struct stack	*stack_a;

	count = argc - 1;
	stack_a = (struct stack *)malloc(sizeof(struct stack));
	if (!stack_a)
		return (NULL);
	stack_a->size = argc - 1;
	stack_a->top = -1;
	stack_a->sorted_length = -2147483649;
	stack_a->numbers = (int *)malloc(sizeof(int) * stack_a->size);
	if (!stack_a->numbers)
		return (free(stack_a), NULL);
	while (count > 0)
		stack_a->numbers[++stack_a->top] = atoi(argv[count--]);
	return (stack_a);
}

struct stack	*make_stack_b(struct stack *stack_a)
{
	struct stack	*stack_b;

	stack_b = (struct stack *)malloc(sizeof(struct stack));
	if (!stack_b)
		return (NULL);
	stack_b->size = stack_a->size;
	stack_b->numbers = (int *)malloc(sizeof(int) * stack_b->size);
	if (!stack_b->numbers)
		return (free(stack_a), NULL);
	stack_b->top = -1;
	return (stack_b);
}

struct nums	*make_sort_arr(struct stack *stack_a)
{
	struct nums *sort_arr;

	sort_arr = (struct nums *)malloc(sizeof(struct nums));
	if (!sort_arr)
		return (NULL);
	sort_arr->arr = (int *)malloc(sizeof(int) * stack_a->size);
	if (!sort_arr->arr)
	{
		printf("failed allocation of nums_a.");
		return (free(sort_arr), NULL);
	}
	sort_arr->pivot = 2147483647;
	return (sort_arr);
}

void	free_stack(struct nums *sort_arr, struct stack *stack_a, struct stack *stack_b)
{
	free(stack_a->numbers);
	free(stack_a);
	free(stack_b->numbers);
	free(stack_b);
	free(sort_arr->arr);
	free(sort_arr);
}
