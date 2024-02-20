/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:36:50 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/20 21:59:32 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_find_closest_smaller_number_in_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_a;
	t_node	*current_b;
	t_node	*target_node;
	int32_t	a_value;
	long	best_match_value;

	current_a = stack_a->top;
	while (current_a != NULL)
	{
		best_match_value = LONG_MIN;
		a_value = current_a->value;
		current_b = stack_b->top;
		while (current_b != NULL)
		{
			if (current_b->value < a_value && current_b->value > best_match_value)
			{
				best_match_value = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
			if (best_match_value == LONG_MIN)
				current_a->target_node = ft_get_highest_val(stack_b);
			else
				current_a->target_node = target_node;
		}
		current_a = current_a->next;
	}
}

void	ft_find_closest_bigger_number_in_a(t_stack *stack_b, t_stack *stack_a)
{
	t_node	*current_a;
	t_node	*current_b;
	t_node	*target_node;
	int32_t	b_value;
	long	best_match_value;

	current_b = stack_b->top;
	while (current_b != NULL)
	{
		best_match_value = LONG_MAX;
		b_value = current_b->value;
		current_a = stack_a->top;
		while (current_a != NULL)
		{
			if (current_a->value > b_value && current_a->value < best_match_value)
			{
				best_match_value = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
			if (best_match_value == LONG_MAX)
				current_b->target_node = ft_get_smallest_val(stack_a);
			else
				current_b->target_node = target_node;
		}
		current_b = current_b->next;
	}
}

void	ft_move_nodes_from_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest;

	while (stack_b->size < 2 && stack_a->size > 3)
		ft_pb(stack_a, stack_b);
	while (stack_a->size > 3)
	{
		ft_index_stack(stack_a);
		ft_index_stack(stack_b);
		ft_calculcate_distance(stack_a);
		ft_calculcate_distance(stack_b);
		ft_find_closest_smaller_number_in_b(stack_a, stack_b);
		cheapest = ft_select_nodes_to_push(stack_a);
		ft_move_selected_nodes_to_top(stack_a, stack_b, cheapest);
		ft_pb(stack_a, stack_b);
	}
}

void	ft_move_nodes_from_b_to_a(t_stack *stack_b, t_stack *stack_a)
{
	t_node	*cheapest;

	while (stack_b->top != NULL)
	{
		ft_index_stack(stack_a);
		ft_index_stack(stack_b);
		ft_calculcate_distance(stack_a);
		ft_calculcate_distance(stack_b);
		ft_find_closest_bigger_number_in_a(stack_b, stack_a);
		cheapest = ft_select_nodes_to_push(stack_b);
		ft_move_selected_nodes_to_top_vb(stack_a, stack_b, cheapest);
		ft_pa(stack_b, stack_a);
	}
}

void	ft_turk_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*smallest_node;

	ft_move_nodes_from_a_to_b(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_move_nodes_from_b_to_a(stack_b, stack_a);
	ft_index_stack(stack_a);
	ft_calculcate_distance(stack_a);
	smallest_node = ft_get_smallest_val(stack_a);
	while (stack_a->top != smallest_node)
	{
		if (smallest_node->r_distance < smallest_node->rr_distance)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
}
