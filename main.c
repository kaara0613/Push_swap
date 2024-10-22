/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:16:17 by kaara             #+#    #+#             */
/*   Updated: 2024/10/18 19:11:39 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUsh_swap.h"

int main (int argc, char **argv)
{
    struct stack stack_a;
    struct stack stack_b;

	make_stack_a(argc, **argv, stack_a);
    make_stack_b(stack_a, stack_b);

    return (0);
}
