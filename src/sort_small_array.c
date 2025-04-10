#include "push_swap.h"

bool	sort_small_case_a(long flag, struct s_stack *stack_a)
{
	if (count_pivot_u(flag, stack_a) <= 2)
	{
		if (stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1])
			sa(stack_a);
		while (stack_a->numbers[stack_a->top] < flag && !check_sort_per_a(stack_a)
			&& stack_a->numbers[stack_a->top] > stack_a->sorted_length)
			ra(stack_a);
		stack_a->sorted_length = stack_a->numbers[0];
		return (true);
	}
    if (count_pivot_u(flag, stack_a) <= 3)
	{
		return (false);
	}
	return (false);
}

bool	sort_small_case_b(long flag, struct s_stack *stack_a, struct s_stack *stack_b)
{
	if (count_pivot_u(flag, stack_b) <= 2)
	{
		if (stack_b->numbers[stack_b->top] > stack_b->numbers[stack_b->top - 1])
			sb(stack_b);
		while (stack_b->top > -1 && stack_b->numbers[stack_b->top] < flag)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		stack_a->sorted_length = stack_a->numbers[0];
		return (true);
	}
    if (count_pivot_u(flag, stack_b) <= 3)
	{
		return (false);
	}
	return (false);
}