/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:47:17 by lschawer          #+#    #+#             */
/*   Updated: 2026/07/24 10:06:42 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

typedef enum e_flag
{
	FLAG_SIMPLE,
	FLAG_MEDIUM,
	FLAG_COMPLEX,
	FLAG_ADAPTIVE,
	FLAG_INVALID
}						t_flag;

typedef enum e_bench
{
	FLAG_BENCH,
	FLAG_BENCH_INVALID,
}						t_bench;

typedef struct s_config
{
	t_flag				flag;
	t_bench				bench;
	int					start;
}						t_config;

typedef struct s_container
{
	int					disorder;
	bool				checker;
	t_flag				flag;
	unsigned int		pa;
	unsigned int		pb;
	unsigned int		rra;
	unsigned int		rrb;
	unsigned int		rrr;
	unsigned int		ra;
	unsigned int		rb;
	unsigned int		rr;
	unsigned int		sa;
	unsigned int		sb;
	unsigned int		ss;
}						t_container;

// parsing
t_flag			check_flag(char *flag);
t_bench			check_bench(char *bench);
t_config		parse_config(int argc, char **argv);
char			*join_args(int argc, char **argv, int start);
char			**parse_input(int argc, char **argv, int start);
char			**ft_split(char const *s, char c);

// stack initiation
int				stack_init(t_stack_node **a, char **num_array);
int				error_syntax(char *str);
int				error_duplicate(t_stack_node *a, int new_nbr);

// nodes
void			append_node(t_stack_node **stack, int nbr);
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*find_last_node(t_stack_node *stack);

// stack utils
int				stack_len(t_stack_node *stack);
void			assign_index(t_stack_node *stack);
void			print_stack(t_stack_node *stack);

// free
void			error_free(t_stack_node **a, char **num_array);
void			free_stack(t_stack_node **stack);
void			free_num_array(char **num_array);

// commands
void			pa(t_stack_node **a, t_stack_node **b, t_container *container);
void			pb(t_stack_node **b, t_stack_node **a, t_container *container);
void			rra(t_stack_node **a, t_container *container);
void			rrb(t_stack_node **b, t_container *container);
void			rrr(t_stack_node **a, t_stack_node **b, t_container *container);
void			ra(t_stack_node **a, t_container *container);
void			rb(t_stack_node **b, t_container *container);
void			rr(t_stack_node **a, t_stack_node **b, t_container *container);
void			sa(t_stack_node **a, t_container *container);
void			sb(t_stack_node **b, t_container *container);
void			ss(t_stack_node **a, t_stack_node **b, t_container *container);

// Algorithm
void			sort_stack(t_stack_node **a, t_config cfg, float disorder);
float			compute_disorder(t_stack_node **a);
void			selection_sort(t_stack_node **a, t_container *container);
void			bucket_sort(t_stack_node **a, t_container *container);
int				get_distance_from_index(t_stack_node *a, int index,
					int max_distance);
void			radix_sort(t_stack_node **a, t_container *container);

// print
// output for '--bench' flag
t_container		init_container(float disorder, bool checker);
const char		*init_flag_strategy(t_container container, t_config config);
void			print_container(t_container container, t_config config);
// t_config
void			print_config(t_config cfg);

// debugg functions
void			print_stack(t_stack_node *stack);
void			print_stack_variant(t_stack_node *stack);
void			print_config(t_config cfg);

#endif
