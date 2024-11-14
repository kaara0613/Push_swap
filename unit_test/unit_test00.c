/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:55:12 by kaara             #+#    #+#             */
/*   Updated: 2024/11/13 17:22:31 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

int main (int argc, char **argv)
{
    struct stack *stack_a;
    struct stack *stack_b;

    if (argc <= 2)
        return (0);
    stack_a = make_stack_a(argc, argv);
    stack_b = make_stack_b(stack_a);

    bool sidv = check_sort_a(*stack_a);
    printf("sidv :%d\n", sidv);

    for (int i = 0; i <= stack_a->top; i++)
        printf("%d:%d\n",i, stack_a->numbers[i]);

    free_stack(stack_a, stack_b);
    return (0);
}
