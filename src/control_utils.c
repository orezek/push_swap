/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:09:15 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/19 21:18:41 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_traverse_stack(t_stack *stack)
{
	t_node	*current;

	current = NULL;
	current = stack->top;
	while (current != NULL)
	{
		ft_printf(":%d ", current->value);
		current = current->next;
	}
	ft_putchar_fd('\n', 1);
}

void	ft_print_value(t_node *node, char *text)
{
	if (node != NULL)
		ft_printf(text, node->value);
	else
		ft_printf("Node is empty!\n");
}

void	ft_print_position(t_node *node, char *text)
{
	if (node != NULL)
		ft_printf(text, node->position);
	else
		ft_printf("Node is empty!\n");
}
