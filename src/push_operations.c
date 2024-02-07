/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:29:51 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/07 17:25:36 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// src_stack->size > 1 && dst_stack->size != 0
void ft_normal(t_stack *src_stack, t_stack *dst_stack)
{
	t_node	*src_temp;
	t_node	*dst_temp;

	src_temp = NULL;
	// src - ok
	src_temp = src_stack->top->next;
	src_temp->prev = NULL;
	// dst
	dst_temp = dst_stack->top;
	// old top.prev = new dst top
	dst_temp->prev = src_stack->top;
	// overwrite dst top to new top
	dst_stack->top = src_stack->top;
	// link new top to the old top by next
	dst_stack->top->next = dst_temp;
	// mark null to the new top prev
	dst_stack->top->prev = NULL;
	// remove one from the counter
	dst_stack->size++;
	// src - ok
	src_stack->top = src_temp;
	src_stack->size--;
}
// src_stack->size >= 1 && dst_stack->size != 0
void ft_nnormal(t_stack *src_stack, t_stack *dst_stack)
{

	// src stack size == 1
	t_node	*src_temp;
	t_node	*dst_temp;

	src_temp = NULL;
	// src - ok
	if (src_stack->size > 1)
	{
		src_temp = src_stack->top->next;
		src_temp->prev = NULL;
	}
	else
		src_stack->bottom = NULL;
	// dst
	dst_temp = dst_stack->top;
	// old top.prev = new dst top
	dst_temp->prev = src_stack->top;
	// overwrite dst top to new top
	dst_stack->top = src_stack->top;
	// link new top to the old top by next
	dst_stack->top->next = dst_temp;
	// mark null to the new top prev
	dst_stack->top->prev = NULL;
	// remove one from the counter
	dst_stack->size++;
	// src - ok
	src_stack->top = src_temp;
	src_stack->size--;
}
// src_stack->size >= 1 && dst_stack->size != 0
void ft_nnnormal(t_stack *src_stack, t_stack *dst_stack)
{

	// src stack size == 1
	t_node	*src_temp;
	t_node	*dst_temp;

	src_temp = NULL;
	dst_temp = NULL;
	// src has at least two nodes
	if (src_stack->size > 1)
	{
		src_temp = src_stack->top->next;
		src_temp->prev = NULL;
	}
	else
	// sr has exactly one node
		src_stack->bottom = NULL;
	// dst is has at least one node
	if (dst_stack->size > 0)
	{
		dst_temp = dst_stack->top;
		// old top.prev = new dst top
		dst_temp->prev = src_stack->top;
		// overwrite dst top to new top
	}
	// dst has no node
	else
		dst_stack->bottom = src_stack->top;
	dst_stack->top = src_stack->top;
	// next is either next node or null
	dst_stack->top->next = dst_temp;
	// mark null to the new top prev
	dst_stack->top->prev = NULL;
	// add one to the dst counter
	dst_stack->size++;
	// src - top is either second or null
	src_stack->top = src_temp;
	// remove one from src counter
	src_stack->size--;
}
void	ft_pop_push(t_stack *src_stack, t_stack *dst_stack)
{
	// src has at least one one
	if (src_stack->size != 0)
	// src_stack->size >= 1 && dst_stack->size >= 0
	{
		ft_nnnormal(src_stack, dst_stack);
	}

	return ;
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

