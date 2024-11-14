/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:55:12 by kaara             #+#    #+#             */
/*   Updated: 2024/11/14 19:49:04 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

void rara(struct stack *stack_a)
{
	ra(stack_a);
}

int	main(int argc, char **argv)
{
	struct stack	*stack_a;
	struct stack	*stack_b;

	if (argc <= 2)
		return (0);
	stack_a = make_stack_a(argc, argv);
	stack_b = make_stack_b(stack_a);
	int pivot;
	pivot = pivot_make(stack_a, stack_b);
	// push_swap(pivot, stack_a, stack_b);
	// check_rotate(pivot, stack_a, stack_b);
	sa(stack_a);
	for (int i = 0; i <= stack_a->top; i++)
		printf("%d", stack_a->numbers[i]);
	printf("\n");
	for (int i = 0; i <= stack_b->top; i++)
		printf("%d", stack_b->numbers[i]);
	free_stack(stack_a, stack_b);
	return (0);
}
