/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:20:01 by kaara             #+#    #+#             */
/*   Updated: 2024/11/11 16:08:36 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static void	rotate(struct stack *stack_temp);
void ra(struct stack *stack_a);
void rb(struct stack *stack_b);

void rr(struct stack *stack_a, struct stack *stack_b)
{
	rotate(stack_a);
    rotate(stack_b);
	printf("rr\n");
}

void ra(struct stack *stack_a)
{
	rotate(stack_a);
    printf ("ra\n");
}

void rb(struct stack *stack_b)
{
	rotate(stack_b);
    printf ("rb\n");
}

static void	rotate(struct stack *stack_temp)
{
    int i;
    int temp;

    i = stack_temp->top;
    temp = stack_temp->numbers[stack_temp->top];
    while (1)
    {
        stack_temp->numbers[i] = stack_temp->numbers[i - 1];
        i--;
        if (i < 0)
        	break ;
    }
    stack_temp->numbers[0] = temp;
}

// static void	rev_rotete(struct stack *stack_temp)
// {
//     int	i;
//     int	temp;

// 	i = 0;
//     temp = stack_temp->numbers[i];
//     while (1)
//     {
//         stack_temp->numbers[i] = stack_temp->numbers[i + 1];
//         i++;
//         if (i > stack_temp->top)
//         	break ;
//     }
//     return (1);
// }

// static void rra(int *stack_a)
// {
//     rev_rotete(stack_a);
//     printf("rra\n");
// }

// static void rrb(int *stack_b)
// {
//     rev_rotete(stack_b);
//     printf("rrb\n");
// }

// static void rrr(struct stack *stack_a, struct stack *stack_b)
// {
//     rev_rotete(stack_a);
//     rev_rotete(stack_b);
//     printf("rrr\n");
// }
