/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errorcase_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:42:42 by kaara             #+#    #+#             */
/*   Updated: 2024/12/02 13:09:40 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_duplicate_nums(struct s_stack *stack)
{
	int	i;
	int	*nums;

	i = 0;
	nums = nums_allocation(stack);
	memcpy(nums, stack->numbers, sizeof(int) * stack->size);
	heap_sort(nums, stack->top + 1);
	while (i < stack->top)
	{
		if (nums[i] == nums[i + 1])
			return (false);
		i++;
	}
	return (true);
}

bool check_args_figure(int argc, char **argv)
{
    int i;
    int j;
	
    i = 0;
    j = 0;
    while (j < argc)
    {
        while (*argv[i] == '\0')
        {
            if (!(48 <= *argv[i] && *argv[i] <= 57))
            	return (false);
        	i++;
        }
        j++;
    }
    return (true);

}

bool check_overflow(int argc, char **argv)
{
    int i;

    i = 0;
    while (i++ < argc)
    {
        if(ft_atoi(*argv++) == LONG_MAX)
        {
			printf("Error\n");
        	return (false);
        }
    }
	return (true);
}