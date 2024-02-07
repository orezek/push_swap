/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:43:03 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/07 18:08:45 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Rotate operations

void	ft_rnormal(t_stack *stack)
{
	t_node	*temp_top_next;
	t_node	*temp_bottom;

	temp_top_next = stack->top->next;
	temp_bottom = stack->bottom;

	// set old bottom next to old top
	stack->bottom->next = stack->top;
	// set old top next to NULL
	stack->top->next = NULL;
	// set old top prev to old bottom
	stack->top->prev = stack->bottom;
	// set bottom to old top
	stack->bottom = stack->top;
	// set new top prev to NULL
	temp_top_next->prev = NULL;
	// set top to new top (old second)
	stack->top = temp_top_next;
}

/*
	Take the top element and put it into bottom
	Edge cases:
	stack.size == 1 || stack-size == 0
		do nothing
	if stack.size > 1
		swap top for bottom
*/
void	ft_rotate(t_stack *stack)
{
	if (stack->size > 1)
	{
		ft_rnormal(stack);
	}
}

void	ft_ra(t_stack *stack_a)
{
	ft_rotate(stack_a);
	ft_putstr_fd("RA\n", 1);
}

void	ft_rb(t_stack *stack_b)
{
	ft_rotate(stack_b);
	ft_putstr_fd("RA\n", 1);
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putstr_fd("RR\n", 1);
}
