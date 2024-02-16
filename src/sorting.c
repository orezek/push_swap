/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:29:59 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/16 19:09:29 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*get_highest_value(t_stack *stack)
{
	t_node	*top;
	t_node	*highest_value;

	top = stack->top;
	highest_value = top;
	while (top != NULL)
	{
		if (top->value > highest_value->value)
			highest_value = top;
		top = top->next;
	}
	return (highest_value);
}

void	ft_sort_three(t_stack *stack)
{
	if (get_highest_value(stack) == stack->bottom)
		ft_sa(stack);
	else if (get_highest_value(stack) == stack->top)
	{
		ft_ra(stack);
		if (!ft_is_stack_sorted_asc(stack))
			ft_sa(stack);
	}
	else
	{
		ft_rra(stack);
		if (!ft_is_stack_sorted_asc(stack))
			ft_sa(stack);
	}
}

int32_t	ft_sort_to_three(t_stack *stack)
{
	if (stack->size == 1)
	{
		ft_printf("Highest value:%d\n", get_highest_value(stack)->value);
		ft_traverse_stack(stack);
		return (1);
	}
	else if (stack->size == 2 && !ft_is_stack_sorted_asc(stack))
	{
		ft_printf("Highest value:%d\n", get_highest_value(stack)->value);
		ft_ra(stack);
		ft_traverse_stack(stack);
		return (1);
	}
	else if (stack->size == 3 && !ft_is_stack_sorted_asc(stack))
	{
		ft_printf("Highest value:%d\n", get_highest_value(stack)->value);
		ft_sort_three(stack);
		ft_traverse_stack(stack);
		return (1);
	}
	else
		return (0);
}

void	ft_turk_sort(t_stack *stack_a, t_stack *stack_b)
{
	;
}
