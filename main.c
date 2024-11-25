/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:16:17 by kaara             #+#    #+#             */
/*   Updated: 2024/11/25 11:03:51 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	struct stack	*stack_a;
	struct stack	*stack_b;
	int				*nums;

	if (argc <= 2)
		return (0);
	nums = NULL;
	stack_a = make_stack_a(argc, argv);
	stack_b = make_stack_b(stack_a);
	stack_a->flag = 2147483647;
	stack_b->flag = 2147483647;
	nums = nums_allocation(nums, stack_a);
	part_pivot_ua(2147483647, nums, stack_a, stack_b);
	free_stack(stack_a, stack_b);
	free(nums);
	return (0);
}
