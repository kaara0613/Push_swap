/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errorcase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:28:29 by kaara             #+#    #+#             */
/*   Updated: 2024/12/02 00:31:38 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_error_args(int argc, char **argv)
{
	if (argc <= 1)
		return (false);
	else if (argc == 2)
	{
		printf("already sorted.");
		return (false);
	}
    else if(!check_args_figure(argc, argv))
    	return (false);
    else if (!check_overflow(argc, argv));
    	return (false);

	return (true);
}

bool	check_error_case(struct s_stack *stack)
{
	if (!check_duplicate_nums(stack))
	{
		printf("There are duplicate numbers.");
		return (false);
	}
	if (check_sort_per_a(stack))
	{
		printf("already sorted.");
		return (false);
	}
	return (true);
}
