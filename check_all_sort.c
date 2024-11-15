/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:54:45 by kaara             #+#    #+#             */
/*   Updated: 2024/11/15 21:36:44 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

bool	check_sort_a(struct stack stack_a)
{
	int	i;

	i = 0;
	if (check_pivot(&stack_a))
		return (false);
	while (--stack_a.flag > 1)	//pivotができた時点でコピー
		rev_rotate(&stack_a);//構造体自体は複製が利用されるがnumbersは値渡しでも実際のコピー元が操作される可能性があるためエラー
	while (1)
	{
		if (stack_a.numbers[i] > stack_a.numbers[i + 1])
			return (false);
		i++;
		if (i < stack_a.top)
			return (true);
	}
	return (false);
}

bool	check_sort_b(struct stack stack_b)
{
	int	i;

	i = 0;
	if (stack_b.top <= 1)
		return (true);
	while (stack_b.flag-- > 1)	//pivotができた時点でコピー
		rev_rotate(&stack_b);
	while (1)
	{
		if (stack_b.numbers[i] < stack_b.numbers[i + 1])
			return (false);
		i++;
		if (i >= stack_b.top)
			break ;
	}
	return (true);
}

bool	check_pivot(struct stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a->numbers[stack_a->size])
	{
		if (stack_a->numbers[i++] > stack_a->max_or_min_value)
			return (true);
	}
	return (false);
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
