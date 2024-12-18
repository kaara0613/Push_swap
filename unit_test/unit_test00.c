/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:55:12 by kaara             #+#    #+#             */
/*   Updated: 2024/12/01 12:45:14 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	int				*nums;
	int				pivot;

	if (argc <= 2)
		return (0);
	nums = NULL;
	stack_a = make_stack_a(argc, argv);
	stack_b = make_stack_b(stack_a);
	nums = nums_allocation(nums, stack_a);
	pivot = pivot_make(nums, stack_a, stack_b);
	pivot = pivot_remake(pivot, nums, stack_a);
	for(int i = 0; i <= stack_a->top; i++)
        printf("%d ", nums[i]);
	printf("\n%d", pivot);
	// part_pivot_ua(pivot, nums, stack_a, stack_b);
	free_stack(stack_a, stack_b);
	free(nums);
	return (0);
}
