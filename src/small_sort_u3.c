#include "push_swap.h"

void	acb_a(struct s_stack *stack_a)
{
	if (stack_a->numbers[stack_a->top - 2] > stack_a->numbers[stack_a->top]
		&& stack_a->numbers[stack_a->top - 2] < stack_a->numbers[stack_a->top - 1])
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
}
void	bac_a(struct s_stack *stack_a)
{
	if (stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1]
		&& stack_a->numbers[stack_a->top] < stack_a->numbers[stack_a->top - 2])
		sa(stack_a);
}

void bca_a(struct s_stack *stack_a)
{
	if (stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 2]
		&& stack_a->numbers[stack_a->top] < stack_a->numbers[stack_a->top - 1])
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
		sa(stack_a);
	}
}

void	cab_a(struct s_stack *stack_a)
{
	if (stack_a->numbers[stack_a->top - 2] < stack_a->numbers[stack_a->top]
        && stack_a->numbers[stack_a->top - 2] > stack_a->numbers[stack_a->top - 1])
	{
		sa(stack_a);
		ra(stack_a);
		sa(stack_a);
	}
}
void	cba_a(struct s_stack *stack_a)
{
	if (stack_a->numbers[stack_a->top - 1] < stack_a->numbers[stack_a->top]
		&& stack_a->numbers[stack_a->top - 1] > stack_a->numbers[stack_a->top - 2])
	{
		sa(stack_a);
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
		sa(stack_a);
	}
}

//----------------------

void	abc_b(struct s_stack *stack_a, struct s_stack *stack_b)
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
	}
}
void	acb_b(struct s_stack *stack_a, struct s_stack *stack_b)//
{
	if (stack_b->top > -1
		&& stack_b->numbers[stack_b->top] < stack_b->numbers[stack_b->top - 1]
		&& stack_b->numbers[stack_b->top] < stack_b->numbers[stack_b->top - 2])
	{
		sb(stack_b);
		pa(stack_a, stack_b);
		sb(stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		ra(stack_a);
		ra(stack_a);
		ra(stack_a);
	}
}

void	bac_b(struct s_stack *stack_a, struct s_stack *stack_b)//
{
	if (stack_b->top > -1
		&& stack_b->numbers[stack_b->top] > stack_b->numbers[stack_b->top - 1]
		&& stack_b->numbers[stack_b->top] < stack_b->numbers[stack_b->top - 2])
	{
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		ra(stack_a);
		ra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
	}
}

void	bca_b(struct s_stack *stack_a, struct s_stack *stack_b)//
{
	if (stack_b->top > -1
		&& stack_b->numbers[stack_b->top] < stack_b->numbers[stack_b->top - 1]
		&& stack_b->numbers[stack_b->top] > stack_b->numbers[stack_b->top - 2])
	{
		sb(stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		ra(stack_a);
		ra(stack_a);
		ra(stack_a);
	}
}

void	cab_b(struct s_stack *stack_a, struct s_stack *stack_b)
{
	if (stack_b->top > -1
		&& stack_b->numbers[stack_b->top] > stack_b->numbers[stack_b->top - 1]
		&& stack_b->numbers[stack_b->top - 1] < stack_b->numbers[stack_b->top - 2])
	{
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		ra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
		ra(stack_a);
	}
}

void	cba_b(struct s_stack *stack_a, struct s_stack *stack_b)//
{
	if (stack_b->top > -1
		&& stack_b->numbers[stack_b->top] > stack_b->numbers[stack_b->top - 1]
		&& stack_b->numbers[stack_b->top - 1] > stack_b->numbers[stack_b->top - 2])
	{
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		ra(stack_a);
		ra(stack_a);
		ra(stack_a);
	}
}

void small_sort_u3a(long flag, struct s_stack *stack_a)
{
	acb_a(stack_a);
	bac_a(stack_a);
	bca_a(stack_a);
	cab_a(stack_a);
	cba_a(stack_a);
	while (stack_a->numbers[stack_a->top] < flag && !check_sort_per_a(stack_a)
		&& stack_a->numbers[stack_a->top] > stack_a->sorted_length)
		ra(stack_a);
	stack_a->sorted_length = stack_a->numbers[0];
}

void small_sort_u3b(struct s_stack *stack_a, struct s_stack *stack_b)
{
	abc_b(stack_a, stack_b);
	acb_b(stack_a, stack_b);
	bac_b(stack_a, stack_b);
	bca_b(stack_a, stack_b);
	cab_b(stack_a, stack_b);
	cba_b(stack_a, stack_b);
	stack_a->sorted_length = stack_a->numbers[0];
}