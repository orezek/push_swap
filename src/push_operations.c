/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:29:51 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/06 21:50:40 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	ft_pop_push(t_stack *from_stack, t_stack *to_stack)
{
	if (from_stack->size != 0)
	{
		t_node	*temp_a;
		t_node	*temp_b;

		temp_a = NULL;
		temp_b = NULL;
		if (from_stack->top->next != NULL)
			temp_b = from_stack->top->next;
		if (to_stack->size != 0)
		{
			temp_a = to_stack->top;
			temp_a->prev = from_stack->top;
		}
		to_stack->top = from_stack->top;
		to_stack->top->next = temp_a;
		to_stack->size++;
		if (to_stack->size == 1 && temp_a != NULL)
			to_stack->bottom = temp_a;
		else
			to_stack->bottom = from_stack->top;
		if (temp_b != NULL)
			temp_b->prev = NULL;
		from_stack->top = temp_b;
		from_stack->size--;
		if (from_stack->size == 1)
			from_stack->bottom = temp_b;
		else if (from_stack->size == 0)
			from_stack->bottom = NULL;
	}
}

void	ft_pb(t_stack *from_stack_a, t_stack *to_stack_b)
{
	ft_pop_push(from_stack_a, to_stack_b);
	ft_putstr_fd("PB\n",1);
}

void ft_pa(t_stack *from_stack_b, t_stack *to_stack_a)
{
	ft_pop_push(from_stack_b, to_stack_a);
	ft_putstr_fd("PA\n",1);
}

