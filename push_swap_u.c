/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 08:53:21 by kaara             #+#    #+#             */
/*   Updated: 2024/11/23 10:18:37 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_flag_u(struct stack *stack) //flag以下の要素数を返す;
{
	int i;
    int temp;

    i = 0;
    temp = stack->top;
    while (temp-- >= 0 && stack->numbers[temp] < stack->flag)
        i++;
    return (i);
}

