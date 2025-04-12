#include "push_swap.h"
#include <stdbool.h>

bool	abc_b(struct s_stack *stack_a, struct s_stack *stack_b)
{
	if (stack_b->top > -1
		&& stack_b->numbers[stack_b->top] < stack_b->numbers[stack_b->top - 1]
		&& stack_b->numbers[stack_b->top - 1] < stack_b->numbers[stack_b->top - 2])
	{
		pa(stack_a, stack_b);
		ra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
        stack_a->sorted_length = stack_a->numbers[0];
        return (true);
	}
    return (false);
}

bool	acb_b(struct s_stack *stack_a, struct s_stack *stack_b)
{
	if (stack_b->top > -1
		&& stack_b->numbers[stack_b->top] < stack_b->numbers[stack_b->top - 2]
		&& stack_b->numbers[stack_b->top - 2] < stack_b->numbers[stack_b->top - 1])
	{
		sb(stack_b);
		pa(stack_a, stack_b);
		sb(stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		ra(stack_a);
		ra(stack_a);
		ra(stack_a);
        stack_a->sorted_length = stack_a->numbers[0];
        return (true);
	}
    return (false);

}

bool	bac_b(struct s_stack *stack_a, struct s_stack *stack_b)
{
	if (stack_b->top > -1
		&& stack_b->numbers[stack_b->top - 1] < stack_b->numbers[stack_b->top]
		&& stack_b->numbers[stack_b->top] < stack_b->numbers[stack_b->top - 2])
	{
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		ra(stack_a);
		ra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
        stack_a->sorted_length = stack_a->numbers[0];
        return (true);
	}
    return (false);
}


bool	bca_b(struct s_stack *stack_a, struct s_stack *stack_b)
{
	if (stack_b->top > -1
		&& stack_b->numbers[stack_b->top - 2] < stack_b->numbers[stack_b->top]
		&& stack_b->numbers[stack_b->top] < stack_b->numbers[stack_b->top - 1])
    {
		sb(stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		ra(stack_a);
		ra(stack_a);
		ra(stack_a);
        stack_a->sorted_length = stack_a->numbers[0];
        return (true);
	}
    return (false);
}

bool	cab_b(struct s_stack *stack_a, struct s_stack *stack_b)
{
	if (stack_b->top > -1
		&& stack_b->numbers[stack_b->top - 1] < stack_b->numbers[stack_b->top - 2]
		&& stack_b->numbers[stack_b->top - 2] < stack_b->numbers[stack_b->top])
	{
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		ra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
		ra(stack_a);
        stack_a->sorted_length = stack_a->numbers[0];
        return (true);
	}
    return (false);
}

bool	cba_b(struct s_stack *stack_a, struct s_stack *stack_b)
{
	if (stack_b->top > -1
		&& stack_b->numbers[stack_b->top - 2] < stack_b->numbers[stack_b->top - 1]
		&& stack_b->numbers[stack_b->top - 1] < stack_b->numbers[stack_b->top])
	{
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		ra(stack_a);
		ra(stack_a);
		ra(stack_a);
        stack_a->sorted_length = stack_a->numbers[0];
        return (true);
	}
    return (false);
}
