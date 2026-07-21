/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:47:17 by lschawer          #+#    #+#             */
/*   Updated: 2026/07/21 13:19:08 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"

// zum debuggen
# include <stdio.h>

//# define INT_MAX	__INT_MAX__
//# define INT_MIN	__INT_MIN__

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef enum e_flag
{
	FLAG_SIMPLE,
	FLAG_MEDIUM,
	FLAG_COMPLEX,
	FLAG_ADAPTIVE,
	FLAG_INVALID
}	t_flag;

typedef struct s_config
{
	t_flag	flag;
	int		start;
}	t_config;

// parsing
t_flag			check_flag(char *flag);
t_config		parse_config(int argc, char **argv);
char			*join_args(int argc, char **argv, int start);
char			**parse_input(int argc, char **argv, int start);
//void			free_tokens(char **tokens);

char			**ft_split(char const *s, char c);

// stack initiation
int				stack_init(t_stack_node **a, char **num_array);
int				error_syntax(char *str);
int				error_duplicate(t_stack_node *a, int new_nbr);

// nodes
void			append_node(t_stack_node **stack, int nbr);
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*find_last_node(t_stack_node *head);

// stack utils
int				stack_len(t_stack_node *stack);
void			assign_index(t_stack_node *stack);
void			print_stack(t_stack_node *stack);

// free
void			error_free(t_stack_node **a, char **num_array);
void			free_stack(t_stack_node **stack);
void			free_num_array(char **num_array);

// commands
void			pa(t_stack_node **a, t_stack_node **b, bool checker);
void			pb(t_stack_node **b, t_stack_node **a, bool checker);
void			rra(t_stack_node **a, bool checker);
void			rrb(t_stack_node **b, bool checker);
void			rrr(t_stack_node **a, t_stack_node **b, bool checker);
void			ra(t_stack_node **a, bool checker);
void			rb(t_stack_node **b, bool checker);
void			rr(t_stack_node **a, t_stack_node **b, bool checker);
void			sa(t_stack_node **a, bool checker);
void			sb(t_stack_node **b, bool checker);
void			ss(t_stack_node **a, t_stack_node **b, bool checker);

// Algorithm


// debugg functions
void			print_stack(t_stack_node *stack);
void			print_stack_variant(t_stack_node *stack);

#endif