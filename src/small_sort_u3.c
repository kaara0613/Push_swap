#include "push_swap.h"

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

void small_sort_u3b(long flag, struct s_stack *stack_a, struct s_stack *stack_b)
{
	abc_b(stack_a, stack_b);
	acb_b(stack_a, stack_b);
    bac_b(stack_a, stack_b);
	bca_b(stack_a, stack_b);
	cab_b(stack_a, stack_b);
	cba_b(stack_a, stack_b);
    while (stack_b->top > -1 && stack_b->numbers[stack_b->top] < flag)
    	ra(stack_a);
	stack_a->sorted_length = stack_a->numbers[0];
}

void	acb_a(struct stack *stack_a)
{
    if (stack_a->numbers[stack_a->top] < stack_a->numbers[stack_a->top - 2]
    	&& stack_a->numbers[stack_a->top - 2] < stack_a->numbers[stack_a->top - 1])
    {
		ra(stack_a);
        sa(stack_a);
        rra(stack_a);
    }
}
void	bac_a(struct stack *stack_a)
{
    if (stack_a->numbers[stack_a->top - 1] < stack_a->numbers[stack_a->top]
    	&& stack_a->numbers[stack_a->top] < stack_a->numbers[stack_a->top - 2])
        sa(stack_a);
}

void bca_a(struct stack *stack_a)
{
    if (stack_a->numbers[stack_a->top - 1] < stack_a->numbers[stack_a->top - 2]
    	&& stack_a->numbers[stack_a->top - 2] < stack_a->numbers[stack_a->top])
    {
		ra(stack_a);
        sa(stack_a);
        rra(stack_a);
        sa(stack_a);
    }
}

void	cab_a(struct stack *stack_a)
{
    if (stack_a->numbers[stack_a->top - 2] < stack_a->numbers[stack_a->top]
    	&& stack_a->numbers[stack_a->top] < stack_a->numbers[stack_a->top - 1])
    {
        sa(stack_a);
		ra(stack_a);
        sa(stack_a);
        rra(stack_a);
    }
}
void	cba_a(struct stack *stack_a)
{
    if (stack_a->numbers[stack_a->top - 2] < stack_a->numbers[stack_a->top - 1]
    	&& stack_a->numbers[stack_a->top - 1] < stack_a->numbers[stack_a->top])
    {
        sa(stack_a);
		ra(stack_a);
        sa(stack_a);
        rra(stack_a);
        sa(stack_a);
    }
}