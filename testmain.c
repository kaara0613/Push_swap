/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:55:04 by kaara             #+#    #+#             */
/*   Updated: 2024/10/22 15:50:47 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int *swap(int *stack)
{
	int temp;

    temp = stack[0];
    stack[0] = stack[1];
	stack[1] = temp;
	return (stack);
}

void ss(int *stack_aa, int *stack_bb)
{
	swap(stack_aa);
    swap(stack_bb);
}

int main (void)
{
	5, 23, 67, 12, 8, 91, 34, 50, 76, 45
    32, 1, 77, 99, 14, 88, 6, 48, 22, 11
    0, 55, 27, 68, 41, 19, 3, 72, 58, 95
    return (0);
}