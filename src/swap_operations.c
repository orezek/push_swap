/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:01:08 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/04 21:26:51 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

void	ft_sa(t_stack *stack_a)
{
	t_node	*second;
	t_node	*third;

	if (stack_a->size == 2)
	{
		second = stack_a->top->next; //same
		stack_a->top->next = NULL;
		stack_a->top->prev = second; //same
		second->next = stack_a->top; //same
		second->prev = NULL; //same
		stack_a->bottom = stack_a->top;
		stack_a->top = second; //same
	}
	else if (stack_a->size > 2)
	{
		second = stack_a->top->next; //same
		third = stack_a->top->next->next;
		third->prev = stack_a->top;
		stack_a->top->prev = second; //same
		second->next = stack_a->top; //same
		second->prev = NULL; //same
		stack_a->top->next = third;
		stack_a->top = second; //same
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
