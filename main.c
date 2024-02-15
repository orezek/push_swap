/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:11:08 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/15 12:15:11 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_stack_sorted(t_stack *stack)
{
	;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	long long mmin = -2147483648;
	long long	mmax = 2147483647;
	// char *test_arg = "-10 1";
	// argc = 2;
	// argv[1] = test_arg;
	ft_init_stack(&stack_a);
	ft_init_stack(&stack_b);
	// load args
	if (ft_load_input(argc, argv, &stack_a))
		return (1);
	// check duplicates
	if (!ft_check_duplicates(&stack_a))
	{
		ft_putstr_fd("Error: Duplicate value found.\n", 2);
		ft_delete_nodes(&stack_a);
		return (1);
	}
// Start sorting:
	// check if the list is sorted
	// check if the list has only one element
	// check if the list has two elements: if not sorted, sort
	// check if the list contains three elements: if not sorted, sort
	// if the list > 3 use Turk algorithm to sort
	// delete the nodes: clenaup
// Test code
	// for (int i = 0; i < 10; i++)
	// {
	// 	ft_push(&stack_a, i);
	// 	ft_push(&stack_b, i);
	// 	ft_ra(&stack_a);
	// }
	// //ft_ra(&stack_a);
	// //ft_pa(&stack_b, &stack_a);

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
