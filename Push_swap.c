/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:23:02 by kaara             #+#    #+#             */
/*   Updated: 2024/10/28 03:39:53 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	partition(struct stack *stack_a, struct stack *stack_b, int pivot);

void quick_sort(struct stack *stack_a, struct stack *stack_b)
{
    int pivot;

    if (stack_a->top <= 1)
    {
        sa(stack_a);
        return ;
    }
	pivot = stack_a->numbers[stack_a->top / 2];// 簡易的に中央値をピボットとする
    partition(stack_a, stack_b, pivot);
    quick_sort(stack_a, stack_b);
    while (stack_b->top >= 0)    // stack_b から stack_a に戻す
        pa(stack_a, stack_b);
}

void partition(struct stack *stack_a, struct stack *stack_b, int pivot)
{
    int original_size;
	int i;

    original_size = stack_a->top + 1;
	i = 0;
    while (i < original_size) 
    {
        if (stack_a->numbers[stack_a->top] < pivot)
        {// スタックbに移動
            pb(stack_a, stack_b);
            i++;
        } 
        else// スタックaを回転
			ra(stack_a);
    }
}
