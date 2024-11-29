/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:16:17 by kaara             #+#    #+#             */
/*   Updated: 2024/11/29 12:44:00 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	struct stack	*stack_a;
	struct stack	*stack_b;
	struct nums		*sort_arr;

	if (argc <= 2)
		return (0);
	stack_a = make_stack_a(argc, argv);
	stack_b = make_stack_b(stack_a);
	sort_arr = make_sort_arr(stack_a);
	part_pivot_ua(sort_arr, stack_a, stack_b);
	free_stack(sort_arr, stack_a, stack_b);
	return (0);
}
