/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:28:45 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/15 13:13:27 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	ft_is_stack_sorted_asc(t_stack *stack)
{
	t_node	*node;
	t_node 	*next_node;
	int32_t	value;

	node = stack->top;
	while (node != NULL && node->next != NULL)
	{
		value = node->value;
		next_node = node->next;
		if (value > next_node->value)
			return (0);
		node = next_node;
	}
	return (1);
}
