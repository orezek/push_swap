/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:01:08 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/03 22:10:11 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

void	ft_sa(t_stack *stack_a)
{
	t_node	*nop;
	t_node	*sop;
	if (stack_a->size > 2)
	{
		// change reference of the third node
		nop = stack_a->top->next->next;
		nop->prev = stack_a->top;
		// change reference of the second - make it first
		sop = stack_a->top->next;
		sop->prev = NULL;
		sop->next = stack_a->top;
		// change reference on the top
		stack_a->top->next = nop;
		stack_a->top->prev = sop;
		// change reference on the stack top
		stack_a->top = sop;
	}
	else if (stack_a->size == 2)
	{
		sop = stack_a->top->next;
		sop->prev = NULL;
		sop->next = stack_a->top;

		stack_a->top->next = NULL;
		stack_a->top->prev = sop;

		stack_a->top = sop;
		stack_a->bottom = sop->next;
	}
}

void	ft_sb(t_stack *stack_b)
{
	ft_sa(stack_b);
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}
