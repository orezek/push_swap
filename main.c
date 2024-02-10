/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:11:08 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/09 22:27:24 by aldokezer        ###   ########.fr       */
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

	for (int i = 0; i < 10; i++)
	{
		ft_push(&stack_a, i);
		ft_push(&stack_b, i);
		ft_ra(&stack_a);
	}
	//ft_ra(&stack_a);
	//ft_pa(&stack_b, &stack_a);

	ft_traverse_stack(&stack_a);
	ft_traverse_stack(&stack_b);

	ft_printf("Stack A size:%d\n", stack_a.size);
	ft_printf("Stack B size:%d\n", stack_b.size);

	ft_print_value(stack_a.top, "Stack A Top:%d\n");
	ft_print_value(stack_a.bottom, "Stack A Bottom:%d\n");
	ft_print_value(stack_b.top, "Stack B Top:%d\n");
	ft_print_value(stack_b.bottom, "Stack B Bottom:%d\n");
	printf("%p\n",stack_a.top);
	printf("%p\n",stack_a.bottom);
	printf("%p\n",stack_b.top);
	printf("%p\n",stack_b.bottom);
	ft_delete_nodes(&stack_a);
	ft_delete_nodes(&stack_b);
	return (0);
}
