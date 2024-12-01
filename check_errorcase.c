/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errorcase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:28:29 by kaara             #+#    #+#             */
/*   Updated: 2024/12/01 12:45:14 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_error_case(struct s_stack *stack)
{
	if (!check_duplicate_nums(stack))
	{
		printf("There are duplicate numbers.");
		return (false);
	}
	if (check_sort_per_a(stack))
	{
		printf("alredy sorted.");
		return (false);
	}
	return (true);
}