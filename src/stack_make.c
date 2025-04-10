/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_make.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:34:32 by kaara             #+#    #+#             */
/*   Updated: 2024/12/02 13:05:41 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_stack	*make_stack_a(int argc, char **argv)
{
	int				count;
	struct s_stack	*stack_a;

	count = argc - 1;
	stack_a = (struct s_stack *)malloc(sizeof(struct s_stack));
	if (!stack_a)
		return (NULL);
	stack_a->size = argc - 1;
	stack_a->top = -1;
	stack_a->sorted_length = LONG_MIN;
	stack_a->rev_flag = 0;
	stack_a->numbers = (int *)malloc(sizeof(int) * stack_a->size);
	if (!stack_a->numbers)
		return (free(stack_a), NULL);
	while (count > 0)
		stack_a->numbers[++stack_a->top] = p_atoi(argv[count--]);
	// int	*tmp = coordinate_compression(stack_a->numbers, stack_a->size);
	// free(stack_a->numbers);
	// stack_a->numbers = tmp;
	return (stack_a);
}

struct s_stack	*make_stack_b(struct s_stack *stack_a)
{
	struct s_stack	*stack_b;

	stack_b = (struct s_stack *)malloc(sizeof(struct s_stack));
	if (!stack_b)
		return (NULL);
	stack_b->size = stack_a->size;
	stack_b->sorted_length = LONG_MIN;
	stack_b->rev_flag = 0;
	stack_b->numbers = (int *)malloc(sizeof(int) * stack_b->size);
	if (!stack_b->numbers)
		return (free(stack_a), NULL);
	stack_b->top = -1;
	return (stack_b);
}

int	*nums_allocation(struct s_stack *stack)
{
	int *nums;

	nums = (int *)malloc(sizeof(int) * stack->size);
	if (!nums)
	{
		printf("failed allocation of nums_a.");
		return (NULL);
	}
	return (nums);
}

void	free_stack(struct s_stack *stack_a, struct s_stack *stack_b)
{
	free(stack_a->numbers);
	free(stack_a);
	free(stack_b->numbers);
	free(stack_b);
}
