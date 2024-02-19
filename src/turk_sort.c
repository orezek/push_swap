/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:36:50 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/19 22:29:40 by aldokezer        ###   ########.fr       */
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

	current = stack->top;
	cheapest = current;
	while (current != NULL && current->next != NULL)
	{
		next = current->next;
		if (ft_nodes_cost(cheapest) > ft_nodes_cost(next))
				cheapest = next;
		current = current->next;
	}
	return (cheapest);
}

int32_t	ft_nodes_cost(t_node *node)
{
	int32_t	node_pair_cost;


	if (node->r_distance <= node->rr_distance)
	{
		// use node r_distance
		if (node->target_node->r_distance <= node->target_node->rr_distance)
		{
			// use target r_distance
			node_pair_cost = node->r_distance + node->target_node->r_distance;
		}
		else
		{
			// use target rr_distance
			node_pair_cost = node->r_distance + node->target_node->rr_distance;
		}
	}
	else
	{
		// use node rr_distance
		if (node->target_node->r_distance <= node->target_node->rr_distance)
		{
			// use target r_distance
			node_pair_cost = node->rr_distance + node->target_node->r_distance;
		}
		else
		{
			// use target rr_distance
			node_pair_cost = node->rr_distance + node->target_node->rr_distance;
		}
	}
	// ft_putnbr_fd(node_pair_cost, 1);
	// ft_putstr_fd("\n", 1);
	return (node_pair_cost);
}

void	ft_move_selected_nodes_to_top(t_stack *stack_a, t_stack *stack_b, t_node *selected_node)
{
	t_node	*node_a;
	t_node	*node_b;

	node_a = selected_node;
	node_b = node_a->target_node;

	if (node_a->r_distance <= node_a->rr_distance && node_b->r_distance <= node_b->rr_distance)
	{
		// both nodes go up rr and r ops
		while (stack_a->top != node_a && stack_b->top != node_b)
			ft_rr(stack_a, stack_b);
		if (stack_a->top != node_a)
		{
			ft_rotate_to_top(stack_a, node_a);
		}
		else if (stack_b->top != node_b)
		{
			ft_rotate_to_top(stack_b, node_b);
		}

	}
	else if (node_a->r_distance > node_a->rr_distance && node_b->r_distance > node_b->rr_distance)
	{
		// both nodes go down rrr and rr ops
		while (stack_a->top != node_a && stack_b->top != node_b)
			ft_rrr(stack_a, stack_b);
		if (stack_a->top != node_a)
		{
			ft_reverse_to_top(stack_a, node_a);
		}
		else if (stack_b->top != node_b)
		{
			ft_reverse_to_top(stack_b, node_b);
		}
	}
	else
	{
		if (node_a->r_distance <= node_a->rr_distance)
		{
			// move node_a to the top in ra
			ft_rotate_to_top(stack_a, node_a);
			ft_putstr_fd("RA\n", 1);
		}
		else if (node_a->r_distance > node_a->rr_distance)
		{
			// move node_a to the top in rra
			ft_reverse_to_top(stack_a, node_a);
			ft_putstr_fd("RRA\n", 1);
		}
		if (node_b->r_distance <= node_b->rr_distance)
		{
			// move node_b to the top in rb
			ft_rotate_to_top(stack_b, node_b);
			ft_putstr_fd("RB\n", 1);
		}
		else if (node_b->r_distance > node_b->rr_distance)
		{
			// move node_b to top in rrb
			ft_reverse_to_top(stack_b, node_b);
			ft_putstr_fd("RRB\n", 1);
		}
	}
}

void	ft_rotate_to_top(t_stack *stack, t_node *node)
{
	while (stack->top != node)
	{
		ft_rotate(stack);
	}
}

void	ft_reverse_to_top(t_stack *stack, t_node *node)
{
	while (stack->top != node)
	{
		ft_re_rotate(stack);
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
	// ft_traverse_stack(stack_a);
	// ft_traverse_stack(stack_b);
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
		while(current_a != NULL)
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


void	ft_move_selected_nodes_to_top_vb(t_stack *stack_a, t_stack *stack_b, t_node *selected_node)
{
	t_node	*node_a;
	t_node	*node_b;

	node_b = selected_node;
	node_a = node_a->target_node;

	if (node_a->r_distance <= node_a->rr_distance && node_b->r_distance <= node_b->rr_distance)
	{
		// both nodes go up rr and r ops
		while (stack_a->top != node_a && stack_b->top != node_b)
			ft_rr(stack_a, stack_b);
		if (stack_a->top != node_a)
		{
			ft_rotate_to_top(stack_a, node_a);
		}
		else if (stack_b->top != node_b)
		{
			ft_rotate_to_top(stack_b, node_b);
		}

	}
	else if (node_a->r_distance > node_a->rr_distance && node_b->r_distance > node_b->rr_distance)
	{
		// both nodes go down rrr and rr ops
		while (stack_a->top != node_a && stack_b->top != node_b)
			ft_rrr(stack_a, stack_b);
		if (stack_a->top != node_a)
		{
			ft_reverse_to_top(stack_a, node_a);
		}
		else if (stack_b->top != node_b)
		{
			ft_reverse_to_top(stack_b, node_b);
		}
	}
	else
	{
		if (node_a->r_distance <= node_a->rr_distance)
		{
			// move node_a to the top in ra
			ft_rotate_to_top(stack_a, node_a);
			ft_putstr_fd("RA\n", 1);
		}
		else if (node_a->r_distance > node_a->rr_distance)
		{
			// move node_a to the top in rra
			ft_reverse_to_top(stack_a, node_a);
			ft_putstr_fd("RRA\n", 1);
		}
		if (node_b->r_distance <= node_b->rr_distance)
		{
			// move node_b to the top in rb
			ft_rotate_to_top(stack_b, node_b);
			ft_putstr_fd("RB\n", 1);
		}
		else if (node_b->r_distance > node_b->rr_distance)
		{
			// move node_b to top in rrb
			ft_reverse_to_top(stack_b, node_b);
			ft_putstr_fd("RRB\n", 1);
		}
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
	ft_traverse_stack(stack_a);
	// first phase
	ft_move_nodes_from_a_to_b(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_traverse_stack(stack_a);
	ft_traverse_stack(stack_b);
	// second phase
	ft_move_nodes_from_b_to_a(stack_b, stack_a);
	// third phase
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
	ft_traverse_stack(stack_a);
	// move biggest to the bottom if applicable
}
