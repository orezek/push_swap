/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:36:50 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/19 14:01:23 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

void	ft_index_stack(t_stack *stack)
{
	int32_t	index;
	t_node	*current;

	index = 1;
	current = stack->top;
	while (current != NULL)
	{
		current->position = index;
		current = current->next;
		index++;
	}
}

void	ft_calculcate_distance(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL)
	{
		current->r_distance = current->position - 1;
		current->rr_distance = (stack->size - current->position) + 1;
		current = current->next;
	}
}

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
		while(current_b != NULL)
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

t_node	*ft_select_nodes_to_push(t_stack *stack)
{
	t_node	*current;
	t_node	*next;
	t_node	*cheapest;

	if (stack == NULL || stack->top->next == NULL)
		return (NULL);
	current = stack->top;
	cheapest = current;
	while (current != NULL && current->next != NULL)
	{
		next = current->next;
		if (cheapest->r_distance + cheapest->target_node->r_distance > next->r_distance + next->target_node->r_distance ||
			cheapest->rr_distance + cheapest->target_node->rr_distance > next->rr_distance + next->target_node->rr_distance)
			{
				cheapest = next;
			}
		current = current->next;
	}
	return (cheapest);
}

void	ft_move_nodes_from_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest;

	while (stack_a->size > 3)
	{
		while (stack_b->size < 1 && stack_a->size > 3)
			ft_pb(stack_a, stack_b);
		ft_pb(stack_a, stack_b);
		ft_index_stack(stack_a);
		ft_index_stack(stack_b);
		ft_calculcate_distance(stack_a);
		ft_calculcate_distance(stack_b);
		ft_find_closest_smaller_number_in_b(stack_a, stack_b);
		cheapest = ft_select_nodes_to_push(stack_a);
		ft_putnbr_fd(cheapest->value, 1);
		// ft_move_selected_nodes_to_top(stack_a, stack_b);
	}
	//ft_find_closest_smaller_number_in_b(stack_a, stack_b);
	ft_traverse_stack(stack_a);
	//ft_traverse_stack(stack_b);
}

void	ft_turk_sort(t_stack *stack_a, t_stack *stack_b)
{
	ft_move_nodes_from_a_to_b(stack_a, stack_b);
	//ft_move_nodes_from_b_to_a();
	// move biggest to the bottom if applicable
}
