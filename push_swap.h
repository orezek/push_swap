/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:27:03 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/21 19:31:58 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>

typedef struct s_node {
	int				value;
	int				position;
	int				r_distance;
	int				rr_distance;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}		t_node;

typedef struct s_stack {
	t_node	*top;
	t_node	*bottom;
	int		size;
}		t_stack;

// swap operations
void	ft_sa(t_stack *stack_a);
void	ft_sb(t_stack *stack_b);
void	ft_ss(t_stack *stack_a, t_stack *stack_b);

// pop/push operatations - pop from stack and push to a stack
void	ft_pa(t_stack *from_stack_b, t_stack *to_stack_a);
void	ft_pb(t_stack *from_stack_a, t_stack *to_stack_b);

// rotate operations
void	ft_ra(t_stack *stack_a);
void	ft_rb(t_stack *stack_b);
void	ft_rr(t_stack *stack_a, t_stack *stack_b);
void	ft_rotate(t_stack *stack);

// reverse rotate operations
void	ft_rra(t_stack *stack_a);
void	ft_rrb(t_stack *stack_b);
void	ft_rrr(t_stack *stack_a, t_stack *stack_b);
void	ft_re_rotate(t_stack *stack);

// program utils
void	ft_delete_nodes(t_stack *stack);
void	ft_init_stack(t_stack *stack);

// control utils
void	ft_traverse_stack(t_stack *stack);
void	ft_print_value(t_node *node, char *text);

// stack utils
void	ft_push(t_stack *stack, int val);
void	ft_pop(t_stack *stack);
t_node	*ft_get_highest_val(t_stack *stack);
t_node	*ft_get_smallest_val(t_stack *stack);

// atol
long	ft_atol(const char *string);

// array utils
void	ft_delete_array(char **array);

// input utils
bool	ft_is_int32(char *arg);
bool	ft_is_valid_nuber(char *str);
void	ft_ra_push(t_stack *stack_a);
bool	ft_arg_is_valid_number(char **args);
bool	ft_check_duplicates(t_stack *stack);
int32_t	ft_convert_input_str(char *argv[], t_stack *stack);
int32_t	ft_convert_args(int argc, char **argv, t_stack *stack);
int		ft_load_input(int argc, char *argv[], t_stack *stack);
bool	ft_is_stack_sorted_asc(t_stack *stack);

// sorting
int32_t	ft_sort_to_three(t_stack *stack);
void	ft_sort_three(t_stack *stack);
void	ft_turk_sort(t_stack *stack_a, t_stack *stack_b);
void	ft_index_stack(t_stack *stack);
void	ft_calculcate_distance(t_stack *stack);
void	ft_find_closest_smaller_number_in_b(t_stack *stack_a, t_stack *stack_b);
t_node	*ft_select_nodes_to_push(t_stack *stack);
int32_t	ft_nodes_cost(t_node *node);
void	ft_reverse_to_top(t_stack *stack, t_node *node, char *str);
void	ft_rotate_to_top(t_stack *stack, t_node *node, char *str);
void	ft_mov_nod_top_a(t_stack *stack_a,
			t_stack *stack_b, t_node *selected_node);
void	ft_find_closest_bigger_number_in_a(t_stack *stack_b,
			t_stack *stack_a);
void	ft_move_nodes_from_a_to_b(t_stack *stack_a, t_stack *stack_b);
void	ft_move_nodes_from_b_to_a(t_stack *stack_b, t_stack *stack_a);
void	ft_mov_nod_top_b(t_stack *stack_a,
			t_stack *stack_b, t_node *selected_node);
#endif
