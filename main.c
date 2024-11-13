/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:16:17 by kaara             #+#    #+#             */
/*   Updated: 2024/11/12 21:21:36 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int main (int argc, char **argv)
{
    // int pivot;
    struct stack *stack_a;
    struct stack *stack_b;

    if (argc <= 2)
    	return (0);
	stack_a = make_stack_a(argc, argv);
    stack_b = make_stack_b(stack_a);
    pb(stack_a, stack_b);
    rev_rotate(stack_a);
	// pivot = pivot_make(stack_a, stack_b);
    // push_swap(pivot, stack_a, stack_b);
    // while (stack_b->top <= -1)
    //     pa(stack_a, stack_b);
	for (int i = 0; i <= stack_a->top; i++)
		printf("%d", stack_a->numbers[i]);
    printf("\n");
    for (int i = 0; i <= stack_b->top; i++)
		printf("%d", stack_b->numbers[i]);
	free_stack(stack_a, stack_b);
    return (0);
}
