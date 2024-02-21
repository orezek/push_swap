/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:47:54 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/21 19:47:47 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int32_t	ft_nodes_cost(t_node *node)
{
	int32_t	node_pair_cost;

	if (node->r_distance <= node->rr_distance)
	{
		if (node->target_node->r_distance <= node->target_node->rr_distance)
			node_pair_cost = node->r_distance + node->target_node->r_distance;
		else
			node_pair_cost = node->r_distance + node->target_node->rr_distance;
	}
	else
	{
		if (node->target_node->r_distance <= node->target_node->rr_distance)
			node_pair_cost = node->rr_distance + node->target_node->r_distance;
		else
			node_pair_cost = node->rr_distance + node->target_node->rr_distance;
	}
	return (node_pair_cost);
}

void	ft_move_ops(t_node *node_a, t_node *node_b, t_stack *stack_a, t_stack *stack_b)
{
	if (node_a->r_distance <= node_a->rr_distance)
		ft_rotate_to_top(stack_a, node_a, "ra\n");
	else if (node_a->r_distance > node_a->rr_distance)
		ft_reverse_to_top(stack_a, node_a, "rra\n");
	if (node_b->r_distance <= node_b->rr_distance)
		ft_rotate_to_top(stack_b, node_b, "rb\n");
	else if (node_b->r_distance > node_b->rr_distance)
		ft_reverse_to_top(stack_b, node_b, "rrb\n");
}

void	ft_mov_nod_top_a(t_stack *stack_a, t_stack *stack_b, t_node *selec_node)
{
	t_node	*node_a;
	t_node	*node_b;

	node_a = selec_node;
	node_b = node_a->target_node;
	if (node_a->r_distance <= node_a->rr_distance && node_b->r_distance <= node_b->rr_distance)
	{
		while (stack_a->top != node_a && stack_b->top != node_b)
			ft_rr(stack_a, stack_b);
		if (stack_a->top != node_a)
			ft_rotate_to_top(stack_a, node_a, "ra\n");
		else if (stack_b->top != node_b)
			ft_rotate_to_top(stack_b, node_b, "rb\n");
	}
	else if (node_a->r_distance > node_a->rr_distance && node_b->r_distance > node_b->rr_distance)
	{
		while (stack_a->top != node_a && stack_b->top != node_b)
			ft_rrr(stack_a, stack_b);
		if (stack_a->top != node_a)
			ft_reverse_to_top(stack_a, node_a, "rra\n");
		else if (stack_b->top != node_b)
			ft_reverse_to_top(stack_b, node_b, "rrb\n");
	}
	else
		ft_move_ops(node_a, node_b, stack_a, stack_b);
}

void	ft_mov_nod_top_b(t_stack *stack_a, t_stack *stack_b, t_node *selec_node)
{
	t_node	*node_a;
	t_node	*node_b;

	node_b = selec_node;
	node_a = node_b->target_node;
	if (node_a->r_distance <= node_a->rr_distance && node_b->r_distance <= node_b->rr_distance)
	{
		while (stack_a->top != node_a && stack_b->top != node_b)
			ft_rr(stack_a, stack_b);
		if (stack_a->top != node_a)
			ft_rotate_to_top(stack_a, node_a, "ra\n");
		else if (stack_b->top != node_b)
			ft_rotate_to_top(stack_b, node_b, "rb\n");
	}
	else if (node_a->r_distance > node_a->rr_distance && node_b->r_distance > node_b->rr_distance)
	{
		while (stack_a->top != node_a && stack_b->top != node_b)
			ft_rrr(stack_a, stack_b);
		if (stack_a->top != node_a)
			ft_reverse_to_top(stack_a, node_a, "rra\n");
		else if (stack_b->top != node_b)
			ft_reverse_to_top(stack_b, node_b, "rrb\n");
	}
	else
		ft_move_ops(node_a, node_b, stack_a, stack_b);
}
