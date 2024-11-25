/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_make_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:40:43 by kaara             #+#    #+#             */
/*   Updated: 2024/11/25 11:02:27 by kaara            ###   ########.fr       */
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

	i = count_pivot_u(stack->flag, stack) - 1;//flagをpivotに変更
	temp_top = stack->top;
	while (i >= 0)
		nums[i--] = stack->numbers[temp_top--];
	heap_sort(nums, stack->top + 1);
	if (stack->top % 2)
		pivot = nums[stack->top / 2 + 1];
	else
		pivot = nums[stack->top / 2];
	stack->flag = pivot;
	return (pivot);
}

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static	void	heapify(int *nums, int n, int i)
{
	int	largest;
	int	left;
	int	right;

	largest = i;
	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left < n && nums[left] > nums[largest])
		largest = left;
	if (right < n && nums[right] > nums[largest])
		largest = right;
	if (largest != i)
	{
		swap(&nums[i], &nums[largest]);
		heapify(nums, n, largest);
	}
}

static void	heap_sort(int *nums, int n)
{
	int	i;

	i = n / 2 - 1;
	while (i >= 0)
	{
		heapify(nums, n, i);
		i--;
	}

	i = n - 1;
	while (i > 0)
	{
		swap(&nums[0], &nums[i]);
		heapify(nums, i, 0);
		i--;
	}
}
