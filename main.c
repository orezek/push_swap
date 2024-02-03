/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:11:08 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/03 19:10:35 by aldokezer        ###   ########.fr       */
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

// remove a node from a stack
void	ft_pop(t_stack *stack)
{
	if (stack->top != NULL && stack->top->next != NULL)
	{
		t_node	*temp;
		temp = stack->top;
		stack->top = stack->top->next;
		temp->next->prev = NULL;
		free(temp);
	}
	else if (stack->top != NULL)
	{
		t_node	*temp;
		temp = stack->top;
		stack->top = NULL;
		free(temp);
	}
}

void	ft_traverse_stack(t_stack *stack)
{
	t_node	*current;
	current = stack->top;
	while(current != NULL)
	{
		ft_printf(":%d ", current->value);
		current = current->next;
	}
}

void	ft_delete_nodes(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while(current != NULL)
	{
		t_node	*temp;
		temp = current->next;
		free(current);
		current = temp;
		temp = NULL;
	}
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
	ft_traverse_stack(&stack_a);

	ft_pop(&stack_a);

	ft_traverse_stack(&stack_a);

	ft_delete_nodes(&stack_a);
	ft_traverse_stack(&stack_a);
	return (0);
}
