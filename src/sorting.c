/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:29:59 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/20 12:20:15 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_three(t_stack *stack)
{
	if (ft_get_highest_val(stack) == stack->bottom)
		ft_sa(stack);
	else if (ft_get_highest_val(stack) == stack->top)
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
		return (1);
	else if (stack->size == 2 && !ft_is_stack_sorted_asc(stack))
	{
		//ft_printf("Highest value:%d\n", ft_get_highest_val(stack)->value);
		ft_ra(stack);
		//ft_traverse_stack(stack);
		return (1);
	}
	else if (stack->size == 3 && !ft_is_stack_sorted_asc(stack))
	{
		//ft_printf("Highest value:%d\n", ft_get_highest_val(stack)->value);
		ft_sort_three(stack);
		//ft_traverse_stack(stack);
		return (1);
	}
	else
		return (0);
}
