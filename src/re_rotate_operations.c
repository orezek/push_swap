/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_rotate_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:48:29 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/09 18:54:01 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Reverse Rotate operations

void	ft_re_rnormal(t_stack *stack)
{
	t_node	*temp_bootom_prev;

	temp_bootom_prev = stack->bottom->prev;
	stack->top->prev = stack->bottom;
	temp_bootom_prev->next = NULL;
	stack->bottom->next = stack->top;
	stack->bottom->prev = NULL;
	stack->top = stack->bottom;
	stack->bottom = temp_bootom_prev;
}

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
	ft_putstr_fd("RRA\n", 1);
}

void	ft_rrb(t_stack *stack_b)
{
	ft_re_rotate(stack_b);
	ft_putstr_fd("RRB\n", 1);
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_re_rotate(stack_a);
	ft_re_rotate(stack_b);
	ft_putstr_fd("RRR\n", 1);
}
