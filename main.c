/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:11:08 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/14 14:25:11 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra_push(t_stack *stack_a)
{
	ft_rotate(stack_a);
}

bool	ft_is_int32(char *arg)
{
	long long	number;

	number = ft_atol(arg);
	if (number <= INT32_MAX && number >= INT32_MIN)
		return (1);
	else
		return (0);
	return (1);

}

bool	ft_is_valid_nuber(char *str)
{
	if (*str == '-')
		str++;
	while(*str != '\0')
		if (!ft_isdigit(*(str++)))
			return (0);
	return (1);
}

bool	ft_arg_is_valid_number(char **args)
{
	char	*str;

	while (*args != NULL)
	{
		str = *args;
		if (ft_is_valid_nuber(str))
			args++;
		else
			return (0);
	}
	return (1);
}

int32_t	ft_convert_input_str(char *argv[], t_stack *stack)
{
	char	**args;
	char	**args_ptr;

	args = ft_split(argv[1], ' ');
	args_ptr = args;
	if (args == NULL)
	{
		ft_putstr_fd("Error: Invalid string argument.\n", 2);
		return (1);
	}
	else if (!ft_arg_is_valid_number(args))
	{
		ft_putstr_fd("Error: Not valid number in the string\n", 2);
		ft_delete_array(args);
		return (1);
	}
	while (*args)
	{
		if (!ft_is_int32(*args))
		{
			ft_putstr_fd("Error: Number is not signed int.\n", 2);
			ft_delete_array(args_ptr);
			ft_delete_nodes(stack);
			return (1);
		}
		else
		{
			ft_push(stack, ft_atoi(*(args++)));
			ft_ra_push(stack);
		}
	}
	ft_delete_array(args_ptr);
	return (0);
}

int32_t	ft_convert_args(int argc, char **argv, t_stack *stack)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_valid_nuber(argv[i]) || !ft_is_int32(argv[i]))
		{
			ft_putstr_fd("Error: Argument is not valid number or signed int!\n", 2);
			ft_delete_nodes(stack);
			return (1);
		}
		else
		{
			ft_push(stack, ft_atoi(argv[i]));
			ft_ra_push(stack);
			i++;
		}
	}
	return (0);
}

int	ft_load_input(int argc, char *argv[], t_stack *stack)
{
	if (argc == 1)
		return (1);
	else if (argc == 2)
	{
		if (ft_convert_input_str(argv, stack))
			return (1);
	}
	else
		if (ft_convert_args(argc, argv, stack))
			return (1);
	return (0);
}

bool	ft_check_duplicates(t_stack *stack)
{
	t_node	*node;
	t_node	*next_node;
	int		val;

	if (stack == NULL)
		return false;
	node = stack->top;
	while (node != NULL)
	{
		val = node->value;
		next_node = node->next;
		while (next_node != NULL)
		{
			if (next_node->value == val)
				return (false);
			next_node = next_node->next;
		}
		node = node->next;
	}
	return (true);
}

int		ft_is_stack_sorted(t_stack *stack)
{
	;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	long long mmin = -2147483648;
	long long	mmax = 2147483647;
	// char *test_arg = "-10 1";
	// argc = 2;
	// argv[1] = test_arg;
	ft_init_stack(&stack_a);
	ft_init_stack(&stack_b);
	// load args
	if (ft_load_input(argc, argv, &stack_a))
		return (1);
	// check duplicates
	if (!ft_check_duplicates(&stack_a))
	{
		ft_putstr_fd("Error: Duplicate value found\n", 2);
		ft_delete_nodes(&stack_a);
		return (1);
	}
// Start sorting:
	// check if the list is sorted
	// check if the list has only one element
	// check if the list has two elements: if not sorted, sort
	// check if the list contains three elements: if not sorted, sort
	// if the list > 3 use Turk algorithm to sort
	// delete the nodes: clenaup
// Test code
	// for (int i = 0; i < 10; i++)
	// {
	// 	ft_push(&stack_a, i);
	// 	ft_push(&stack_b, i);
	// 	ft_ra(&stack_a);
	// }
	// //ft_ra(&stack_a);
	// //ft_pa(&stack_b, &stack_a);

	ft_traverse_stack(&stack_a);
	ft_traverse_stack(&stack_b);

	ft_printf("Stack A size:%d\n", stack_a.size);
	ft_printf("Stack B size:%d\n", stack_b.size);

	ft_print_value(stack_a.top, "Stack A Top:%d\n");
	ft_print_value(stack_a.bottom, "Stack A Bottom:%d\n");
	ft_print_value(stack_b.top, "Stack B Top:%d\n");
	ft_print_value(stack_b.bottom, "Stack B Bottom:%d\n");
	printf("%p\n",stack_a.top);
	printf("%p\n",stack_a.bottom);
	printf("%p\n",stack_b.top);
	printf("%p\n",stack_b.bottom);
	ft_delete_nodes(&stack_a);
	ft_delete_nodes(&stack_b);
	return (0);
}
