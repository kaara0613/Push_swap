/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_make.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:34:32 by kaara             #+#    #+#             */
/*   Updated: 2024/11/23 11:46:53 by kaara            ###   ########.fr       */
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

int	*nums_allocation(int *nums, struct stack *stack_a)
{
	nums = (int *)malloc(sizeof(int) * stack_a->size);
	if (!nums)
	{
		printf("failed allocation of nums_a.");
		return (NULL);
	}
	return (nums);
}

bool	free_stack(struct stack *stack_a, struct stack *stack_b)
{
	free(stack_a->numbers);
	free(stack_a);
	free(stack_b->numbers);
	free(stack_b);
	return (true);
}
