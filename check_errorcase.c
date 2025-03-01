/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errorcase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:28:29 by kaara             #+#    #+#             */
/*   Updated: 2024/12/02 15:14:47 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_error_args(int argc, char **argv)
{
	if (argc <= 1)
		return (false);
	if (argc == 2)
	{
		printf("already sorted.");
		return (false);
	}
    if(!check_args_figure(argc, argv))
		return (false);
    if (!check_overflow(argc, argv))
		return (false);
	return (true);
}

bool	check_error_case(t_stack *stack)
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
