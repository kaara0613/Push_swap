/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errorcase_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:42:42 by kaara             #+#    #+#             */
/*   Updated: 2025/04/14 16:13:29 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_libft.h"
#include "ft_printf.h"
#include <limits.h>

bool	check_duplicate_nums(struct s_stack *stack)
{
	int	i;
	int	*nums;

	i = 0;
	nums = nums_allocation(stack);
	ft_memcpy(nums, stack->numbers, sizeof(int) * stack->size);
	heap_sort(nums, stack->top + 1);
	while (i < stack->top)
	{
		if (nums[i] == nums[i + 1])
			return (false);
		i++;
	}
	free(nums);
	return (true);
}

bool	check_args_figure(int argc, char **argv)
{
	int	j;
	int	i;

	j = 1;
	while (j < argc)
	{
		i = 1;
		if (argv[j][0] != '+' && argv[j][0] != '-'
			&& !('0' <= argv[j][0] && argv[j][0] <= '9'))
		{
			ft_printf("Error\n");
			return (false);
		}
		while (argv[j][i] != '\0')
		{
			if (!('0' <= argv[j][i] && argv[j][i] <= '9'))
			{
				ft_printf("Error\n");
				return (false);
			}
			i++;
		}
		j++;
	}
	return (true);
}

bool	check_overflow(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i++ < argc)
	{
		if (p_atoi(*argv++) == LONG_MAX)
		{
			ft_printf("Error\n");
			return (false);
		}
	}
	return (true);
}
