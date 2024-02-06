/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:29:51 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/06 20:43:26 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	ft_pa(t_stack *from_stack_b, t_stack *to_stack_a)
{
	if (from_stack_b->size != 0)
	{
		t_node	*temp_a;
		t_node	*temp_b;

		temp_a = NULL;
		temp_b = NULL;
		if (from_stack_b->top->next != NULL)
			temp_b = from_stack_b->top->next;
		temp_a = to_stack_a->top;
		temp_a->prev = from_stack_b->top;
		to_stack_a->top = from_stack_b->top;
		to_stack_a->top->next = temp_a;
		to_stack_a->size++;
		if (to_stack_a->size == 1)
			to_stack_a->bottom = temp_a;
		if (temp_b != NULL)
			temp_b->prev = NULL;
			from_stack_b->top = temp_b;
		from_stack_b->size--;
		if (from_stack_b->size == 1)
			from_stack_b->bottom = temp_b;
	}
}


void	ft_pb(t_stack *from_stack_a, t_stack *to_stack_b)
{
	ft_pa(from_stack_a, to_stack_b);
}

