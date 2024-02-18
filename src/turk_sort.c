/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:36:50 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/18 21:33:01 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

void	ft_move_nodes_from_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 3)
	{
		while (stack_b->size < 2 && stack_a->size > 3)
			ft_pb(stack_a, stack_b);
		ft_index_stack(stack_a);
		ft_index_stack(stack_b);
		ft_find_closest_smaller_number_in_b(stack_a, stack_b);
		ft_select_nodes_to_push(stack_a);
		ft_move_efficiently_selected_nodes_to_top(stack_a, stack_b);
		ft_pb(stack_a, stack_b);
	}
}

void	ft_turk_sort(t_stack *stack_a, t_stack *stack_b)
{
	ft_move_nodes_from_a_to_b(stack_a, stack_b);
	//ft_move_nodes_from_b_to_a();
	// move biggest to the bottom if applicable
}
