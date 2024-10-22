/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_use.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:08:39 by kaara             #+#    #+#             */
/*   Updated: 2024/10/22 14:06:39 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static int is_empty(struct stack *stack_temp)
{
	return (stack_temp->top == -1);
}

static int is_full(struct stack *stack_temp)
{
	return (stack_temp->top == stack_temp->size - 1);
}
//要素の追加
static int put(int	input_value, struct stack *stack_temp)
{
	if (is_full(stack_temp))
    {	
        printf("This stack is full.");
		return (0);
    }
	stack_temp->numbers[stack_temp->top + 1] = input_value;
    return (1);
}

//要素の取り出し
static int pop(struct stack *stack_temp)
{
    int return_value;
	
    if (is_empty(stack_temp))
    {
        printf("This stack is empty");
    	return (0);
    }
	return_value = stack_temp->numbers[stack_temp->top];
	stack_temp->numbers[stack_temp->top] = 0;
	stack_temp->top -= 1;
    return (return_value);
}
