/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_make.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:34:32 by kaara             #+#    #+#             */
/*   Updated: 2024/10/18 19:15:58 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static int	make_stack_a(int	argc, char	**argv, struct stack	stack_a)
{
    int	count;

    count = 0;
	stack_a.size = argc - 1;
    stack_a.numbers = (int *)malloc(sizeof(int) * stack_a.size);
    if (stack_a.numbers == NULL)
    {
    	printf("filed allocation to stack_a.numbers");
        return (0);
    }
    while(1)
    {
		stack_a.numbers[count] = atoi(*argv[count]);
        if (count == stack_a.size)
        	break ;
    }
    stack_a.top = stack_a.size;
	return (1);
}

static int	make_stack_b(struct stack	stack_a, struct stack	stack_b)
{
    stack_b.size = stack_a.size;
    stack_b.numbers = (int *)malloc(sizeof(int) * stack_b.size);
    if (stack_b.numbers == NULL)
    {
    	printf("filed allocation to stack_b.numbers");
        return (0);
    }
    stack_b.top = -1;
    return (1);
}
