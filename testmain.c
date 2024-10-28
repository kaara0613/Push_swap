/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:55:04 by kaara             #+#    #+#             */
/*   Updated: 2024/10/28 19:31:30 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int main(int argc, char **argv)
{
	int temp = 0;
	struct stack *stack_a;
	struct stack *stack_b;
	
	stack_a = make_stack_a(argc, argv);
	stack_b = make_stack_b(stack_a);
    for (int i = 0; i < stack_a->size; i++)
        stack_b->numbers[i] = stack_a->numbers[i];
	for (int i = 0; i < stack_b->size; i++)
		printf("%d\n", stack_b->numbers[i]);
	temp = pop(stack_a);
	printf("%d\n", temp);
	put(temp, stack_b);
	printf("%d\n", stack_b->numbers[stack_b->top]);
	free (stack_a->numbers);
	free (stack_a);
	free (stack_b->numbers);
	free (stack_b);
	return (0);
}

struct stack	*make_stack_a(int	argc, char	**argv)
{
	struct stack *stack_a;
    int	count;

	stack_a = NULL;
	count = 0;
    stack_a = (struct stack *)malloc(sizeof(struct stack));
    if (!stack_a)
        return (NULL);
	stack_a->size = argc - 1;
    stack_a->numbers = (int *)malloc(sizeof(int) * stack_a->size);
    if (!stack_a->numbers)
        return (NULL);
    while(1)
    {
		stack_a->numbers[count] = atoi(argv[count + 1]);
        count++;
        if (count == stack_a->size)
        	break ;
    }
    stack_a->top = stack_a->size - 1;
	return (stack_a);
}

struct stack	*make_stack_b(struct stack	*stack_a)
{
	struct stack	*stack_b;

	stack_b = NULL;
    stack_b = (struct stack *)malloc(sizeof(struct stack));
    if (!stack_b)
        return (NULL);
    stack_b->size = stack_a->size;
    stack_b->numbers = (int *)malloc(sizeof(int) * stack_b->size);
    if (!stack_b->numbers)
        return (NULL);
    stack_b->top = -1;
    return (stack_b);
}

bool is_empty(struct stack *stack_temp)
{
	return (stack_temp->top == -1);
}

bool is_full(struct stack *stack_temp)
{
	return (stack_temp->top == stack_temp->size - 1);
}
//要素の追加
bool put(int	input_value, struct stack *stack_temp)
{
	if (is_full(stack_temp))
    {	
        printf("This stack is full.");
		return (false);
    }
	stack_temp->numbers[stack_temp->top + 1] = input_value;
	stack_temp->top++;
    return (true);
}

//要素の取り出し
int pop(struct stack *stack_temp)
{
    int return_value;
	
    if (is_empty(stack_temp))
    {
        printf("This stack is empty");
    	return (-1);
    }
	return_value = stack_temp->numbers[stack_temp->top];
	stack_temp->numbers[stack_temp->top] = 0;
	stack_temp->top--;
    return (return_value);
}
