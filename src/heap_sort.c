/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:12:56 by kaara             #+#    #+#             */
/*   Updated: 2025/04/14 15:49:28 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b);
static void	heapify(int *arr, int n, int i);

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

void	heap_sort(int *nums, int n)
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
