/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:12:08 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/09 19:15:08 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_stack *stack, int val)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->value = val;
	node->next = stack->top;
	node->prev = NULL;
	if (stack->top != NULL)
		stack->top->prev = node;
	if (stack->top == NULL)
		stack->bottom = node;
	stack->top = node;
	stack->size++;
}

void	ft_pop(t_stack *stack)
{
	t_node	*temp;

	if (stack->top != NULL && stack->top->next != NULL)
	{
		temp = stack->top;
		stack->top = stack->top->next;
		temp->next->prev = NULL;
		stack->size--;
		free(temp);
	}
	else if (stack->top != NULL)
	{
		temp = stack->top;
		stack->top = NULL;
		stack->size--;
		free(temp);
	}
}
