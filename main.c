/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:16:17 by kaara             #+#    #+#             */
/*   Updated: 2024/11/28 10:34:14 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	struct stack	*stack_a;
	struct stack	*stack_b;
	int				*nums;
	int				temp;
	int				*pivot;

	if (argc <= 2)
		return (0);
	nums = NULL;
	pivot = NULL;
	stack_a = make_stack_a(argc, argv);
	stack_b = make_stack_b(stack_a);
	temp = 2147483647;
	pivot = &temp;
	nums = nums_allocation(nums, stack_a);
	pivot_reset_int_max(pivot, stack_a, stack_b);
	part_pivot_ua(pivot, nums, stack_a, stack_b);
	free_stack(nums, stack_a, stack_b);
	return (0);
}
