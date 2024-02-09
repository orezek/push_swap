/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:07:27 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/09 19:17:46 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_delete_nodes(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	current = stack->top;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
		temp = NULL;
	}
	stack->top = NULL;
}

void	ft_init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}