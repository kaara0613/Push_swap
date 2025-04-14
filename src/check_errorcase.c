/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errorcase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:28:29 by kaara             #+#    #+#             */
/*   Updated: 2025/04/14 15:48:42 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

bool	check_error_args(int argc, char **argv)
{
	if (argc <= 1)
		return (false);
	else if (argc == 2)
		return (false);
	if (!check_args_figure(argc, argv))
		return (false);
	if (!check_overflow(argc, argv))
		return (false);
	return (true);
}

bool	check_error_case(struct s_stack *stack)
{
	if (!check_duplicate_nums(stack))
	{
		ft_printf("Error\n");
		return (false);
	}
	if (check_sort_per_a(stack))
		return (false);
	return (true);
}
