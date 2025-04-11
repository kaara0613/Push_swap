#include "push_swap.h"

void small_sort_u2a(long flag, struct s_stack *stack_a)
{
	if (stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1])
		sa(stack_a);
	while (stack_a->numbers[stack_a->top] < flag && !check_sort_per_a(stack_a)
		&& stack_a->numbers[stack_a->top] > stack_a->sorted_length)
		ra(stack_a);
	stack_a->sorted_length = stack_a->numbers[0];
}

void small_sort_u2b(long flag, struct s_stack *stack_a, struct s_stack *stack_b)
{
	if (stack_b->numbers[stack_b->top] > stack_b->numbers[stack_b->top - 1])
		sb(stack_b);
	while (stack_b->top > -1 && stack_b->numbers[stack_b->top] < flag)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	stack_a->sorted_length = stack_a->numbers[0];
}
