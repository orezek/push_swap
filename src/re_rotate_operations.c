/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_rotate_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:48:29 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/07 20:45:06 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Reverse Rotate operations

void	ft_re_rnormal(t_stack *stack)
{
	t_node	*temp_bootom_prev;

	temp_bootom_prev = stack->bottom->prev;

	// Node links
	// set bottom to the top prev
	stack->top->prev = stack->bottom;
	// set second last next to NULL
	temp_bootom_prev->next = NULL;
	// set new top next to old top
	stack->bottom->next = stack->top;
	// set new top prev to NULL:
	stack->bottom->prev = NULL;
	// Stack links
	// set top to the old bottom
	stack->top = stack->bottom;
	// set bottom to old second bottom
	stack->bottom = temp_bootom_prev;
}

/*
	Take the top element and put it into bottom
	Edge cases:
	stack.size == 1 || stack-size == 0
		do nothing
	if stack.size > 1
		swap bottom for top
*/
void	ft_re_rotate(t_stack *stack)
{
	if (stack->size > 1)
	{
		ft_re_rnormal(stack);
	}
}

void	ft_rra(t_stack *stack_a)
{
	ft_re_rotate(stack_a);
	ft_putstr_fd("RA\n", 1);
}

void	ft_rrb(t_stack *stack_b)
{
	ft_re_rotate(stack_b);
	ft_putstr_fd("RA\n", 1);
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_re_rotate(stack_a);
	ft_re_rotate(stack_b);
	ft_putstr_fd("RRR\n", 1);
}
