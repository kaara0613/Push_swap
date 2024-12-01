/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:16:17 by kaara             #+#    #+#             */
/*   Updated: 2024/12/01 14:35:35 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;

	// if (!check_error_args(argc, argv))
	// 	return (0);
	stack_a = make_stack_a(argc, argv);
	stack_b = make_stack_b(stack_a);
	if (!check_error_case(stack_a))
		return (0);
	push_swap_a(2147483647, 2147483647, stack_a, stack_b);
	free_stack(stack_a, stack_b);
	return (0);
}
