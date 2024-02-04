/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:01:08 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/04 18:51:38 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

void	ft_sa(t_stack *stack_a)
{
	t_node	*nop;
	t_node	*sop;

	if (stack_a->size > 1 && stack_a->size < 3)
	{
		sop = stack_a->top->next;
		stack_a->top->next = NULL;
		stack_a->top->prev = sop;
		sop->next = stack_a->top;
		sop->prev = NULL;
		stack_a->bottom = stack_a->top;
		stack_a->top = sop;
	}
	else if (stack_a->size > 2)
	{
		sop = stack_a->top->next;
		nop = stack_a->top->next->next;
		nop->prev = stack_a->top;
		sop->next = stack_a->top;
		sop->prev = NULL;
		stack_a->top->prev = sop;
		stack_a->top->next = nop;
		stack_a->top = sop;
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
