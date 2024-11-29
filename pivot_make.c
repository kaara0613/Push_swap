/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_make.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:02:36 by kaara             #+#    #+#             */
/*   Updated: 2024/11/29 13:48:41 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pivot_remake(int flag, struct nums *sort_arr, struct stack *stack)
{
	int	temp_top;
	int count;
	int i;

	i = count_pivot_u(flag, stack) - 1;//flagをpivotに変更
	count = i;
	temp_top = stack->top;
	while (i >= 0)
		sort_arr->arr[i--] = stack->numbers[temp_top--];
	heap_sort(sort_arr->arr, count + 1);
	if (count % 2)
		sort_arr->pivot = sort_arr->arr[count / 2 + 1];
	else
		sort_arr->pivot = sort_arr->arr[count / 2];
	if (flag == 2147483647)
		flag = sort_arr->pivot;
	memset(sort_arr->arr, 0, sizeof(int) * (count + 1));
}

void	return_pivot_remake(int *pivot, int *nums, struct stack *current_stack, struct stack *return_stack)
{
	int	temp_top;
	int max;
	int count;

	if (current_stack->top <= 1)
	{
		*pivot = current_stack->numbers[current_stack->top] + 1;
		return ;
	}
	count = -1;
	// for(int t = 0; t <= current_stack->top; t++)
	// 	printf("%d,", current_stack->numbers[t]);
	// printf("\n");
	temp_top = current_stack->top;
	if (return_stack->top == -1)
		max = 2147483647;
	else
		max = return_stack->numbers[return_stack->top];
	while (temp_top >= 0 && *pivot <= current_stack->numbers[temp_top] 
		&& current_stack->numbers[temp_top] < max)
		nums[++count] = current_stack->numbers[temp_top--];
	// for(int s = 0; s <= count; s++)
	// 	printf("%d,", nums[s]);
	printf("\n");
	heap_sort(nums, count + 1);
	if (count % 2)
		*pivot = nums[count / 2 + 1];
	else
		*pivot = nums[count / 2];
	// current_stack->flag = return_stack->numbers[return_stack->top];
	// return_stack->flag = 2147483647;
	memset(nums, 0, sizeof(int) * count);
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
