/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:11:08 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/11 15:41:05 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool ft_is_valid_nuber(char *str)
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

void	ft_split_input_str(char *argv[], t_stack *stack)
{
	char	**args;
	args = ft_split(argv[1], ' ');
	if (args == NULL)
	{
		exit(1);
		// remove exit and handle it with return
		// print error messages to std out 2
	}
	if (!ft_arg_is_valid_number(args))
		exit(1);
		// remove exit and handle it with return
		// print error messages to std out 2 and cleanup
	while (*args)
		{
			ft_push(stack, ft_atoi(*(args++)));
			ft_ra(stack);
		}
}

void	ft_convert_args(int argc, char **argv, t_stack *stack)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_valid_nuber(argv[i]))
		{
			ft_putstr_fd("Error: Invalid number!\n", 2);
			exit (1);
			// implement the same error handling as for ft_split_input_str
			// clean the stack because in the else you add nodes to it
		}
		else
		{
			ft_push(stack, ft_atoi(argv[i]));
			ft_ra(stack);
			i++;
		}
	}
}

int	ft_load_input(int argc, char *argv[], t_stack *stack)
{
	if (argc == 1)
		return (1);
	else if (argc == 2)
		ft_split_input_str(argv, stack);
	else
		ft_convert_args(argc, argv, stack);

	// check no of arguments
	// if two it's string with numbers
		// split the string into separate strings
	// if more then two, each argument is a separate number
		// keep separate strings
	// convert the strings into int
	// check if the number is valid int32 - || +
// leftmost number should be at the top of the stack
	// push and rotate each number to have the proper order
	// return the stack - use pointer to a stack
	return (0);
}

void	ft_check_duplicates(t_stack *stack)
{
	;
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

	// char *test_arg = "-10 1";
	// argc = 2;
	// argv[1] = test_arg;
	ft_init_stack(&stack_a);
	ft_init_stack(&stack_b);
	if (ft_load_input(argc, argv, &stack_a))
		return (1);
	// load args
	// check duplicates
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
