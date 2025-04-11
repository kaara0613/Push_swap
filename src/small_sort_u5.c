#include "push_swap.h"

void cba_a2(struct s_stack *stack_a)
{
    if (stack_a->numbers[stack_a->top - 1] < stack_a->numbers[stack_a->top]
		&& stack_a->numbers[stack_a->top - 1] > stack_a->numbers[stack_a->top - 2])
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void bca_a2(struct s_stack *stack_a)
{
	if (stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 2]
		&& stack_a->numbers[stack_a->top] < stack_a->numbers[stack_a->top - 1])
		rra(stack_a);
}

void	acb_a2(struct s_stack *stack_a)
{
	if (stack_a->numbers[stack_a->top - 2] > stack_a->numbers[stack_a->top]
		&& stack_a->numbers[stack_a->top - 2] < stack_a->numbers[stack_a->top - 1])
	{
		rra(stack_a);
		sa(stack_a);
	}
}

void	cab_a2(struct s_stack *stack_a)
{
	if (stack_a->numbers[stack_a->top - 2] < stack_a->numbers[stack_a->top]
        && stack_a->numbers[stack_a->top] < stack_a->numbers[stack_a->top - 1])
		ra(stack_a);
}

void small_sort_u5(struct s_stack *stack_a, struct s_stack *stack_b)
{
    if (stack_a->top == 1)
    {
        if (stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1])
        	sa(stack_a);
    }
    else if (stack_a->top == 2)
    {
        cba_a2(stack_a);
        bca_a2(stack_a);
        acb_a2(stack_a);
        cab_a2(stack_a);
        bac_a(stack_a);
    }
    else if (stack_a->top <= 4)
    	(void)stack_b;
}