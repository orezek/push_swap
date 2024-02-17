/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:10:11 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/17 18:33:26 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int32_t	ft_convert_args(int argc, char **argv, t_stack *stack)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_valid_nuber(argv[i]) || !ft_is_int32(argv[i]))
		{
			ft_putstr_fd("Error: Arg is not valid number or signed int!\n", 2);
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

int32_t	ft_convert_input_str(char *argv[], t_stack *stack)
{
	char	**args;
	char	**args_ptr;

	args = ft_split(argv[1], ' ');
	args_ptr = args;
	if (args == NULL)
		return (ft_putstr_fd("Error: Invalid string argument.\n", 2), 1);
	else if (!ft_arg_is_valid_number(args))
		return (ft_putstr_fd("Error: Invalid number in the string.\n", 2),
			ft_delete_array(args), 1);
	while (*args)
	{
		if (!ft_is_int32(*args))
		{
			ft_putstr_fd("Error: Number is not signed int.\n", 2);
			return (ft_delete_array(args_ptr), ft_delete_nodes(stack), 1);
		}
		else
		{
			ft_push(stack, ft_atoi(*(args++)));
			ft_ra_push(stack);
		}
	}
	return (ft_delete_array(args_ptr), 0);
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
			return (false);
	}
	return (true);
}

bool	ft_check_duplicates(t_stack *stack)
{
	t_node	*node;
	t_node	*next_node;
	int		val;

	if (stack == NULL)
		return (false);
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
