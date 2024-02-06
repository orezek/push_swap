/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:27:03 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/06 20:46:56 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_node {
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}		t_node;

typedef struct s_stack {
	t_node	*top;
	t_node	*bottom;
	int		size;
}		t_stack;

// swap operations
void	ft_sa(t_stack *stack);
void	ft_sb(t_stack *stack_b);
void	ft_ss(t_stack *stack_a, t_stack *stack_b);

// pop/push operatations - pop from stack and push to a stack
void	ft_pa(t_stack *from_stack_b, t_stack *to_stack_a);
void	ft_pb(t_stack *from_stack_a, t_stack *to_stack_b);

#endif
