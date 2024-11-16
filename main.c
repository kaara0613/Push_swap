/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:16:17 by kaara             #+#    #+#             */
/*   Updated: 2024/11/16 14:52:05 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"
//args 4 6 5 1 8 3 7 2
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
	// sorted_rev(stack_a, stack_b);
	free_stack(stack_a, stack_b);
	return (0);
}
