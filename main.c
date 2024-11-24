/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:16:17 by kaara             #+#    #+#             */
/*   Updated: 2024/11/25 00:01:25 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	struct stack	*stack_a;
	struct stack	*stack_b;
	int				*nums;
	int				*pivot;

	if (argc <= 2)
		return (0);
	nums = NULL;
	pivot = NULL;
	stack_a = make_stack_a(argc, argv);
	stack_b = make_stack_b(stack_a);
	nums = nums_allocation(nums, stack_a);
	*pivot = 2147483647;
	part_pivot_ua(pivot, nums, stack_a, stack_b);
	free_stack(stack_a, stack_b);
	free(nums);
	return (0);
}
