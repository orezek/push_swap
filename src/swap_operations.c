/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:01:08 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/20 17:42:35 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_operation(t_stack *stack)
{
	t_node	*second;
	t_node	*third;

	second = NULL;
	third = NULL;
	second = stack->top->next;
	if (second->next != NULL)
	{
		third = second->next;
		third->prev = stack->top;
		stack->top->next = third;
	}
	stack->top->prev = second;
	second->prev = NULL;
	if (stack->size == 2)
	{
		stack->top->next = NULL;
		stack->bottom = stack->top;
	}
	second->next = stack->top;
	stack->top = second;
}

void	ft_swap_stack(t_stack *stack)
{
	if (stack->size > 1)
	{
		ft_swap_operation(stack);
	}
}

void	ft_sa(t_stack *stack_a)
{
	ft_swap_stack(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stack *stack_b)
{
	ft_swap_stack(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap_stack(stack_a);
	ft_swap_stack(stack_b);
	ft_putstr_fd("ss\n", 1);
}
