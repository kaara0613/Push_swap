/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:16:17 by kaara             #+#    #+#             */
/*   Updated: 2024/12/02 13:07:37 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;

	if (!check_error_args(argc, argv))
		return(0);
	stack_a = make_stack_a(argc, argv);
	stack_b = make_stack_b(stack_a);
	if(!check_error_case(stack_a))
		return (0);
	if (stack_a->top <= 4)
		small_sort_u5(stack_a, stack_b);
	push_swap_a(LONG_MAX, LONG_MAX, stack_a, stack_b);
	free_stack(stack_a, stack_b);
	return (0);
}
