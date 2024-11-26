/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 08:53:21 by kaara             #+#    #+#             */
/*   Updated: 2024/11/26 14:39:02 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_pivot_u(int flag, struct stack *stack) //flag以下の要素数を返す;
{
	int i;
    int temp;

    i = 0;
    temp = stack->top;
    while (stack->numbers[temp--] < flag && temp >= -1)
        i++;
    return (i);
}

int count_pivot(int flag, struct stack *stack) //flag以下の要素数を返す;
{
	int i;
    int temp;

    i = 0;
    temp = stack->top;
    while (temp-- >= 0 && stack->numbers[temp] >= flag)
        i++;
    return (i);
}
