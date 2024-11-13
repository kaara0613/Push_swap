/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_make.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:34:32 by kaara             #+#    #+#             */
/*   Updated: 2024/11/12 21:27:23 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

struct stack	*make_stack_a(int	argc, char	**argv)
{
	struct stack *stack_a;
    int	count;

	stack_a = NULL;
	count = 0;
    stack_a = (struct stack *)malloc(sizeof(struct stack));
    if (!stack_a)
        return (NULL);
	stack_a->size = argc - 1;
    stack_a->numbers = (int *)malloc(sizeof(int) * stack_a->size);
    if (!stack_a->numbers)
        return (free(stack_a), NULL);
    while(1)
    {
		stack_a->numbers[count] = atoi(argv[count + 1]);
        count++;
        if (count == stack_a->size)
        	break ;
    }
    stack_a->top = stack_a->size - 1;
	return (stack_a);
}

struct stack	*make_stack_b(struct stack	*stack_a)
{
	struct stack	*stack_b;

	stack_b = NULL;
    stack_b = (struct stack *)malloc(sizeof(struct stack));
    if (!stack_b)
        return (NULL);
    stack_b->size = stack_a->size;
    stack_b->numbers = (int *)malloc(sizeof(int) * stack_b->size);
    if (!stack_b->numbers)
        return (NULL);
    stack_b->top = -1;
    return (stack_b);
}

bool	free_stack(struct stack *stack_a, struct stack *stack_b)
{
	free(stack_a->numbers);
    free(stack_a);
    free(stack_b->numbers);
    free(stack_b);
    return (true);
}
