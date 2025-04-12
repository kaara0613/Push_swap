#include "push_swap.h"
#include "ft_printf.h"

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


void small_sort_u3a(long flag, struct s_stack *stack_a, struct s_stack *stack_b)
{
	acb_a(stack_a);
	bac_a(stack_a);
	bca_a(stack_a);
	cab_a(stack_a);
	cba_a(stack_a);
	while (stack_a->numbers[stack_a->top] < flag
		&& (!check_sort_per_a(stack_a) || stack_b->top != -1)
		&& stack_a->numbers[stack_a->top] > stack_a->sorted_length)
		ra(stack_a);
	stack_a->sorted_length = stack_a->numbers[0];
}

void small_sort_u3b(long flag, struct s_stack *stack_a, struct s_stack *stack_b)
{
	if (stack_b->top > -1 && stack_b->numbers[stack_b->top] < flag)
	{
		if (abc_b(stack_a, stack_b))
			return ;
		else if (acb_b(stack_a, stack_b))
			return ;
		else if (bac_b(stack_a, stack_b))
			return ;
		else if (bca_b(stack_a, stack_b))
			return ;
		else if (cab_b(stack_a, stack_b))
			return ;
		else if (cba_b(stack_a, stack_b))
			return ;
	}
}