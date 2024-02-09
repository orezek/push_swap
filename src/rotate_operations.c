/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:43:03 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/09 18:54:56 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Rotate operations

void	ft_rnormal(t_stack *stack)
{
	t_node	*temp_top_next;

	temp_top_next = stack->top->next;
	stack->bottom->next = stack->top;
	stack->top->next = NULL;
	stack->top->prev = stack->bottom;
	stack->bottom = stack->top;
	temp_top_next->prev = NULL;
	stack->top = temp_top_next;
}

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
