/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:11:08 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/20 12:21:14 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	ft_init_stack(&stack_a);
	ft_init_stack(&stack_b);
	if (ft_load_input(argc, argv, &stack_a))
		return (1);
	if (!ft_check_duplicates(&stack_a))
	{
		ft_putstr_fd("Error: Duplicate value found.\n", 2);
		ft_delete_nodes(&stack_a);
		return (1);
	}
	if (ft_is_stack_sorted_asc(&stack_a))
		return (ft_delete_nodes(&stack_a), 0);
	if (!ft_sort_to_three(&stack_a))
	{
		ft_turk_sort(&stack_a, &stack_b);
		ft_delete_nodes(&stack_a);
		return (0);
	}
	ft_delete_nodes(&stack_a);
	return (0);
}
