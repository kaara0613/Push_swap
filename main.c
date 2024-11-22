/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:16:17 by kaara             #+#    #+#             */
/*   Updated: 2024/11/22 19:29:26 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	struct stack	*stack_a;
	struct stack	*stack_b;
	int				*nums;
	int				pivot;

	if (argc <= 2)
		return (0);
	nums = NULL;
	stack_a = make_stack_a(argc, argv);
	stack_b = make_stack_b(stack_a);
	pivot = pivot_make(stack_a, stack_b, nums);
	return (0);
	partition_pivot(pivot, stack_a, stack_b, nums);
	// insertion_sort(pivot, stack_a, stack_b);
	free_stack(stack_a, stack_b);
	free(nums);
	return (0);
}
