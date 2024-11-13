/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:02:36 by kaara             #+#    #+#             */
/*   Updated: 2024/11/13 17:03:58 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int pivot_make(struct stack	*stack_a, struct stack	*stack_b)
{
    int pivot;

    pivot = 5;
	int stack_b_max_or_min_value = 1;
    stack_flag_make(pivot, stack_a);
    stack_flag_make(stack_b_max_or_min_value, stack_b);
    return (pivot);
}

void stack_flag_make(int max_or_min_value, struct stack	*stack_temp)
{
    int i;

    i = 0;
	stack_temp->max_or_min_value = max_or_min_value;
    while(i <= stack_temp->top && stack_temp->numbers[i] != max_or_min_value)
    		i++;
    if (stack_temp->numbers[i] == max_or_min_value)
    	stack_temp->flag = stack_temp->top - (i - 1);
}
