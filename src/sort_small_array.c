#include "push_swap.h"

bool	sort_small_case_a(long flag, struct s_stack *stack_a, struct s_stack *stack_b)
{
    // if (count_pivot_u(flag, stack_a) == 3)
	// {
    //     small_sort_u3a(flag, stack_a, stack_a);
	// 	return (true);
	// }
	if (count_pivot_u(flag, stack_a) <= 2)
	{
        small_sort_u2a(flag, stack_a, stack_b);
		return (true);
	}
	return (false);
}

bool	sort_small_case_b(long flag, struct s_stack *stack_a, struct s_stack *stack_b)
{
    // if (count_pivot_u(flag, stack_b) == 3)
	// {
    //     small_sort_u3b(flag, stack_a, stack_b);
	// 	return (true);
	// }
	if (count_pivot_u(flag, stack_b) <= 2)
	{
        small_sort_u2b(flag, stack_a, stack_b);
		return (true);
	}
	return (false);
}