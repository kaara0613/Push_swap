/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_make_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:40:43 by kaara             #+#    #+#             */
/*   Updated: 2024/11/23 11:03:04 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	heap_sort(int *nums, int n);
static void	swap(int *a, int *b);
static void	heapify(int *arr, int n, int i);

int	pivot_remake(int pivot, int *nums, struct stack *stack)
{
	int	temp_top;
	int i;

	i = count_flag_u(stack) - 1;
	temp_top = stack->top;
	stack->flag = pivot;
	printf("%d\n%d", i, temp_top);
	return 0;
	while(i >= 0)//segufo
		nums[i--] = stack->numbers[temp_top--];
	heap_sort(nums, stack->top);
	if (!(stack->top / 2))
		pivot = (nums[stack->top / 2] + nums[stack->top / 2 + 1]) / 2;
	else
		pivot = nums[stack->top / 2 + 1];
	return (pivot);
}

static void	heap_sort(int *nums, int n)
{
	int	left_i;
	int	right_i;

	left_i = n / 2 - 1;
	right_i = n - 1;
	while (left_i-- >= 0)
		heapify(nums, n, left_i);
	while (right_i-- > 0)
	{
		swap(&nums[0], &nums[right_i]);
		heapify(nums, right_i, 0);
	}
}

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	heapify(int *arr, int n, int i)
{
	int	largest;
	int	left;
	int	right;

	largest = i;
	left = 2 * i + 1;
	right = 2 * i + 2;
	if (left < n && arr[left] > arr[largest])
		largest = left;
	if (right < n && arr[right] > arr[largest])
		largest = right;
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}
