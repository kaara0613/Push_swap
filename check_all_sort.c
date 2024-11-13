/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:54:45 by kaara             #+#    #+#             */
/*   Updated: 2024/11/13 11:02:59 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

bool check_rotate(int pivot, struct stack	*stack_a, struct stack	*stack_b)
{//そのうちPush_swap.cへ移動
    bool a;
    bool b;

    a = check_sort_a(*stack_a);
    b = check_sort_b(*stack_b);
    if (pivot <= stack_a->numbers[stack_a->top])
    {
		if (a == false && b == false)
		{
    		rr(stack_a, stack_b);
        	return (false);
    	}
    	else if (a == false)
    	{
    		ra(stack_a);
        	return (false);
    	}
    	else if (b == false)
    	{
			rb(stack_b);
        	return (false);
    	}
    }
    else if(pivot >= stack_a->numbers[stack_a->top])
    	return (false);
    return (true);
}

bool	check_sort_a(struct stack	stack_a)
{
    int	i;

    i = 0;
    while (stack_a.flag--)//pivotができた時点でコピー
        rev_rotate(&stack_a);
    while (i < stack_a.top)
    {
		if(stack_a.numbers[i] < stack_a.numbers[i + 1])
        	return (false);
        i++;
    }
    return (true);
}

bool	check_sort_b(struct stack	stack_b)
{
    int	i;

    i = 0;
    while (stack_b.flag--)//pivotができた時点でコピー
        rev_rotate(&stack_b);
    while (i < stack_b.top)
    {
		if(stack_b.numbers[i] > stack_b.numbers[i + 1])
        	return (false);
        i++;
    }
    return (true);
}

// void	rev_rotate(int pivot, struct stack	*stack_a, struct stack	*stack_b)
// {
//     int stack_a_i;
//     int	stack_b_i;
//     int rrr_i;

//     stack_a_i = stack_a->flag;
//     stack_b_i = stack_b->flag;
// 	if (check_rev_rotate_a(stack_a) == true && check_rev_rotate_b(stack_b) == true)
//     {
//     	if (stack_a_i > stack_b_i)
//         {
//     		rrr_i = stack_b_i;
//             while (rrr_i--)
//     			rrr(stack_a, stack_b);
//             stack_a_i -= stack_b_i;
//             while (stack_a_i--)
//             	rra(stack_a);
//         }
//     	else
//         {
//     		rrr_i = stack_a_i;
//             while (rrr_i--)
//     			rrr(stack_a, stack_b);
//             stack_b_i -= stack_a_i;
//             while (stack_b_i--)
//             	rrb(stack_b);
//         }
//         return ;
//     }
//     push_swap(pivot, stack_a, stack_b);
// }



    // while (stack_a_i++ <= stack_a->flag)//pivotができた時点でコピー
    //     rev_rotete(stack_a);
    // while (stack_b_i++ <= stack_b->flag)//sortedができた時点でコピー
    //     rev_rotete(stack_b);
