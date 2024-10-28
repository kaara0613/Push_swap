/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:16:17 by kaara             #+#    #+#             */
/*   Updated: 2024/10/28 03:38:34 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int main (int argc, char **argv)
{
    struct stack *stack_a;
    struct stack *stack_b;

	stack_a = make_stack_a(argc, argv);;
    stack_b = make_stack_b(stack_a);
    quick_sort(stack_a, stack_b);
	for (int i = 0; i < stack_a->size; i++)
		printf("%d", stack_a->numbers[i]);
    free (stack_a->numbers);
    free (stack_a);
    free (stack_b->numbers);
    free (stack_b);
    return (0);
}
