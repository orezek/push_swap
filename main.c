/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:11:08 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/09 19:18:14 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	char	*str = "push_swap!\n";
	ft_printf("%s", str);

	t_stack	stack_a;
	t_stack	stack_b;

	ft_init_stack(&stack_a);
	ft_init_stack(&stack_b);

	for (int i = 0; i < 1554540; i++)
	{
		ft_push(&stack_a, i);
		ft_push(&stack_b, i);
		ft_ss(&stack_a, &stack_b);
		ft_pa(&stack_b, &stack_a);
		ft_rr(&stack_a, &stack_b);
		ft_rr(&stack_a, &stack_b);
		ft_pb(&stack_a, &stack_b);
		ft_ss(&stack_a, &stack_b);
		ft_rr(&stack_a, &stack_b);
		ft_rr(&stack_a, &stack_b);
		ft_ss(&stack_a, &stack_b);
	}
	ft_ss(&stack_a, &stack_b);
	ft_pa(&stack_b, &stack_a);
	ft_rr(&stack_a, &stack_b);
	ft_rr(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	ft_ss(&stack_a, &stack_b);
	ft_rr(&stack_a, &stack_b);
	ft_rr(&stack_a, &stack_b);
	ft_ss(&stack_a, &stack_b);
	ft_rr(&stack_a, &stack_b);
	ft_rrr(&stack_a, &stack_b);
	ft_rrr(&stack_a, &stack_b);
	ft_rr(&stack_a, &stack_b);
	ft_rr(&stack_a, &stack_b);
	ft_rr(&stack_a, &stack_b);
	ft_rrr(&stack_a, &stack_b);
	ft_rrr(&stack_a, &stack_b);
	ft_rrr(&stack_a, &stack_b);
	ft_rrr(&stack_a, &stack_b);
	ft_rr(&stack_a, &stack_b);
	ft_rrr(&stack_a, &stack_b);
	ft_rrr(&stack_a, &stack_b);
	ft_rrr(&stack_a, &stack_b);
	ft_rrr(&stack_a, &stack_b);

	ft_traverse_stack(&stack_a);
	ft_traverse_stack(&stack_b);

	ft_printf("Stack A size:%d\n", stack_a.size);
	ft_printf("Stack B size:%d\n", stack_b.size);

	ft_printf("Stack A Top:%d\n", stack_a.top->value);
	ft_printf("Stack A Bottom:%d\n", stack_a.bottom->value);
	ft_printf("Stack B Top:%d\n", stack_b.top->value);
	ft_printf("Stack B Bottom:%d\n", stack_b.bottom->value);

	printf("%p\n",stack_b.top);
	printf("%p\n",stack_b.bottom);
	printf("%p\n",stack_a.top);
	printf("%p\n",stack_a.bottom);
	ft_delete_nodes(&stack_a);
	ft_delete_nodes(&stack_b);
	return (0);
}
