/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:11:08 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/07 17:20:37 by aldokezer        ###   ########.fr       */
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
	if (stack->top == NULL)
		stack->bottom = node;
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
		stack->size--;
		free(temp);
	}
	else if (stack->top != NULL)
	{
		t_node	*temp;
		temp = stack->top;
		stack->top = NULL;
		stack->size--;
		free(temp);
	}
}

// traverses a t_stack and prints the values
void	ft_traverse_stack(t_stack *stack)
{
	t_node	*current;
	current = NULL;
	current = stack->top;

	while(current != NULL)
	{
		ft_printf(":%d ", current->value);
		current = current->next;
	}
	ft_putchar_fd('\n', 1);
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
	stack->top = NULL;
}

int	main(void)
{
	char	*str = "push_swap!\n";
	ft_printf("%s", str);

	t_stack	stack_a;
	t_stack	stack_b;

	ft_init_stack(&stack_a);
	ft_init_stack(&stack_b);

	for (int i = 0; i < 10; i++)
	{
		ft_push(&stack_a, i);
		ft_push(&stack_b, i);
	}
	ft_traverse_stack(&stack_a);
	ft_traverse_stack(&stack_b);

	//ft_ss(&stack_a, &stack_b);
	ft_traverse_stack(&stack_a);
	ft_traverse_stack(&stack_b);

	ft_printf("Stack A size:%d\n", stack_a.size);
	ft_printf("Stack B size:%d\n", stack_b.size);

	ft_printf("Stack A Top:%d\n", stack_a.top->value);
	ft_printf("Stack A Bottom:%d\n", stack_a.bottom->value);
	ft_printf("Stack B Top:%d\n", stack_b.top->value);
	ft_printf("Stack B Bottom:%d\n", stack_b.bottom->value);
	//ft_ss(&stack_a, &stack_b);
	ft_pa(&stack_b, &stack_a);
	ft_pa(&stack_b, &stack_a);
	ft_pa(&stack_b, &stack_a);
	ft_pa(&stack_b, &stack_a);
	ft_pa(&stack_b, &stack_a);
	ft_pa(&stack_b, &stack_a);
	ft_pa(&stack_b, &stack_a);
	ft_pa(&stack_b, &stack_a);
	ft_pa(&stack_b, &stack_a);
	ft_pa(&stack_b, &stack_a);
	ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	// ft_printf("Stack A Top:%d\n", stack_a.top->value);
	// ft_printf("Stack A Bottom:%d\n", stack_a.bottom->value);
	ft_printf("Stack B Top:%d\n", stack_b.top->value);
	ft_printf("Stack B Bottom:%d\n", stack_b.bottom->value);
	// ft_printf("Stack A size:%d\n", stack_a.size);
	// ft_printf("Stack B size:%d\n", stack_b.size);
	ft_traverse_stack(&stack_a);
	ft_traverse_stack(&stack_b);
	printf("%p\n",stack_b.top);
	printf("%p\n",stack_b.bottom);
	ft_delete_nodes(&stack_a);
	ft_delete_nodes(&stack_b);
	return (0);
}
