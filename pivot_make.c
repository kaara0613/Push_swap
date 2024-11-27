/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_make.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:02:36 by kaara             #+#    #+#             */
/*   Updated: 2024/11/26 19:50:33 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pivot_remake(int *pivot, int *nums, struct stack *stack)
{
	int	temp_top;
	int i;

	stack->flag = *pivot;
	i = count_pivot_u(*pivot, stack) - 1;//flagをpivotに変更
	temp_top = stack->top;
	while (i >= 0)
		nums[i--] = stack->numbers[temp_top--];
	heap_sort(nums, stack->top + 1);
	if (stack->top % 2)
		*pivot = nums[stack->top / 2 + 1];
	else
		*pivot = nums[stack->top / 2];
	if (stack->flag == 2147483647)
		stack->flag = *pivot;
}

void	return_pivot_remake(int *pivot, int *nums, struct stack *current_stack, struct stack *return_stack)
{
	int	temp_top;
	int max;
	int i;
	int count;

	i = 0;
	count = 0;
	// for(int t = 0; t <= current_stack->top; t++)
	// 	printf("%d,", current_stack->numbers[t]);
	// printf("\n");
	temp_top = return_stack->top;
	if (return_stack->top == -1)
		max = 2147483647;
	else
		max = return_stack->numbers[return_stack->top];
	while (temp_top >= 0 && *pivot <= return_stack->numbers[temp_top] 
		&& return_stack->numbers[temp_top] < max)
	{
		count++;
		temp_top--;
	}
	temp_top = current_stack->top;
	while(i < count && i >= 0)
		nums[i++] = current_stack->numbers[temp_top--];
	// for(int s = 0; s <= current_stack->top; s++)
	// 	printf("%d,", nums[s]);
	// printf("\n");
	heap_sort(nums, i);
	if (i % 2)
		*pivot = nums[i / 2];
	else
		*pivot = nums[i / 2 - 1];
	memset(nums, 0, sizeof(int) * i);
}

// void	pivot_make(int *pivot, int *nums, struct stack *stack_a, struct stack *stack_b)
// {

// 	stack_a->flag = pivot;
// 	stack_b->flag = pivot;
// }

// void	stack_flag_make(int value, struct stack *stack_temp)
// {
// 	int	i;

// 	i = 0;
// 	if (stack_temp->top < 0)
// 	{
// 		stack_temp->flag = -1;
// 		return ;
// 	}
// 	else
// 	{
// 		while (i <= stack_temp->top)
// 		{
// 			if (stack_temp->numbers[i] == value)
// 			{
// 				stack_temp->flag = i;
// 				return ;
// 			}
// 			i++;
// 		}
// 	}
// }
