/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:11:08 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/01 19:01:20 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

// create a node and add it to a stack
void	ft_push(t_stack *stack, int val)
{
	t_node *node;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->value = val;
	node->next = stack->top;
	node->prev = NULL;

	if (stack->top != NULL)
		stack->top->prev = node;
	stack->top = node;
	stack->size++;
}

int	main(void)
{
	char	*str = "push_swap!\n";
	ft_printf("%s", str);

	t_stack	stack_a;
	ft_init_stack(&stack_a);

	for (int i; i < 10; i++)
	{
		ft_push(&stack_a, i);
	}
	t_node	*current;
	current = stack_a.top;
	while(current != NULL)
	{
		ft_printf(":%d ", current->value);
		current = current->next;
	}
	return (0);
}
