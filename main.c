/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:16:17 by kaara             #+#    #+#             */
/*   Updated: 2024/11/19 11:50:24 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

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
	push_swap(stack_a, stack_b);
	insertion_sort(stack_a, stack_b);
	// sorted_rev(stack_a, stack_b);
	free_stack(stack_a, stack_b);
	return (0);
}
