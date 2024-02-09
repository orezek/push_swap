/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:29:51 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/09 18:58:03 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_nnnormal(t_stack *src_stack, t_stack *dst_stack)
{
	t_node	*src_temp;
	t_node	*dst_temp;

	src_temp = NULL;
	dst_temp = NULL;
	if (src_stack->size > 1)
	{
		src_temp = src_stack->top->next;
		src_temp->prev = NULL;
	}
	else
		src_stack->bottom = NULL;
	if (dst_stack->size > 0)
	{
		dst_temp = dst_stack->top;
		dst_temp->prev = src_stack->top;
	}
	else
		dst_stack->bottom = src_stack->top;
	dst_stack->top = src_stack->top;
	dst_stack->top->next = dst_temp;
	dst_stack->top->prev = NULL;
	dst_stack->size++;
	src_stack->top = src_temp;
	src_stack->size--;
}

void	ft_pop_push(t_stack *src_stack, t_stack *dst_stack)
{
	if (src_stack->size != 0)
	{
		ft_nnnormal(src_stack, dst_stack);
	}
	return ;
}

void	ft_pb(t_stack *from_stack_a, t_stack *to_stack_b)
{
	ft_pop_push(from_stack_a, to_stack_b);
	ft_putstr_fd("PB\n", 1);
}

void	ft_pa(t_stack *from_stack_b, t_stack *to_stack_a)
{
	ft_pop_push(from_stack_b, to_stack_a);
	ft_putstr_fd("PA\n", 1);
}
