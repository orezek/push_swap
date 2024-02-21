/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:36:50 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/21 19:24:37 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_find_closest_smaller_number_in_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cur_a;
	t_node	*cur_b;
	t_node	*target_node;
	long	best_match_value;

	cur_a = stack_a->top;
	while (cur_a != NULL)
	{
		best_match_value = LONG_MIN;
		cur_b = stack_b->top;
		while (cur_b != NULL)
		{
			if (cur_b->value < cur_a->value && cur_b->value > best_match_value)
			{
				best_match_value = cur_b->value;
				target_node = cur_b;
			}
			cur_b = cur_b->next;
			if (best_match_value == LONG_MIN)
				cur_a->target_node = ft_get_highest_val(stack_b);
			else
				cur_a->target_node = target_node;
		}
		cur_a = cur_a->next;
	}
}

void	ft_find_closest_bigger_number_in_a(t_stack *stack_b, t_stack *stack_a)
{
	t_node	*cur_a;
	t_node	*cur_b;
	t_node	*target_node;
	long	best_match_value;

	cur_b = stack_b->top;
	while (cur_b != NULL)
	{
		best_match_value = LONG_MAX;
		cur_a = stack_a->top;
		while (cur_a != NULL)
		{
			if (cur_a->value > cur_b->value && cur_a->value < best_match_value)
			{
				best_match_value = cur_a->value;
				target_node = cur_a;
			}
			cur_a = cur_a->next;
			if (best_match_value == LONG_MAX)
				cur_b->target_node = ft_get_smallest_val(stack_a);
			else
				cur_b->target_node = target_node;
		}
		cur_b = cur_b->next;
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
	t_node	*biggest_node;

	ft_move_nodes_from_a_to_b(stack_a, stack_b);
	if (!ft_is_stack_sorted_asc(stack_a))
		ft_sort_three(stack_a);
	ft_move_nodes_from_b_to_a(stack_b, stack_a);
	ft_index_stack(stack_a);
	ft_calculcate_distance(stack_a);
	smallest_node = ft_get_smallest_val(stack_a);
	biggest_node = ft_get_highest_val(stack_a);
	if (smallest_node != stack_a->top)
	{
		while (stack_a->top != smallest_node)
		{
			if (smallest_node->r_distance < smallest_node->rr_distance)
				ft_ra(stack_a);
			else
				ft_rra(stack_a);
		}
	}
}
