/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:01:40 by kaara             #+#    #+#             */
/*   Updated: 2024/11/23 12:30:11 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int main()
{
    int nums[] = {4, 10, 3, 5, 1, 7 ,11 ,6 ,9};
    int n = sizeof(nums) / sizeof(nums[0]);
    int j = 0;

    printf("元の配列: ");
    while (j < n)
    {
        printf("%d ", nums[j]);
        j++;
    }
    printf("\n");

    heap_sort(nums, n);

    printf("ソート後の配列: ");
    j = 0;
    while (j < n)
    {
        printf("%d ", nums[j]);
        j++;
    }
    printf("\n");

    return 0;
}
