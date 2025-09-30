/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:37:18 by jriga             #+#    #+#             */
/*   Updated: 2025/09/04 01:30:34 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

/* ************************************************************************** */
/*                                  TYPES                                     */
/* ************************************************************************** */

typedef struct s_dir
{
	int	index;
	int	dir;
	int	cost;
}	t_dir;

typedef struct s_stack
{
	t_list	*lst;
	char	name;
	t_dir	*dir;
	size_t	size;
}	t_stack;

typedef enum s_error
{
	NONE,
	MEMORY_ERROR,
	ALGO_ERROR,
	INPUT_ERROR
}	t_error;

/* ************************************************************************** */
/*                               INSTRUCTIONS                                 */
/* ************************************************************************** */

void	swap(t_stack *stack, t_bool print);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stack, t_bool print);
void	rrotate(t_stack *stack, t_bool print);
void	swap_all(t_stack *stack_a, t_stack *stack_b);
void	rotate_all(t_stack *stack_a, t_stack *stack_b);
void	rrotate_all(t_stack *stack_a, t_stack *stack_b);

/* ************************************************************************** */
/*                               INITIALISATION                               */
/* ************************************************************************** */

t_list	*stack_init(int count, char **strs);
void	push_init(int count, char **strs, t_stack **a, t_stack **b);
t_bool	stack_index(t_stack **stack);
t_dir	*dir_init(t_stack *stack, int index_min, int index_max);
void	fill_index(int *index, t_list *lst);
void	assign_indices(t_list *lst, int *index, size_t size);

/* ************************************************************************** */
/*                                ALGORITHMES                                 */
/* ************************************************************************** */

void	pushswap_algo(t_stack *stack_a, t_stack *stack_b);
int		push_index(t_stack *a, t_stack *b, int index);
void	quick_sort_d(t_dir *tab, int low, int high);

/* ************************************************************************** */
/*                              OUTILS DIRECTION                              */
/* ************************************************************************** */

t_dir	find_dir_inferior(int index, t_dir *dir, int size);
int		calculate_cost(t_dir a, t_dir b);
void	dir_to_instructs(int *dir, t_dir a, t_dir b);
void	instructs_action(t_stack *a, t_stack *b, int *instructs);
t_dir	find_best_dir_u(t_stack *a, t_stack *b, int *instructs);
int		count_in_chunk(t_stack *a, int low, int high);

/* ************************************************************************** */
/*                                  VALIDATION                                */
/* ************************************************************************** */

t_bool	verif_order(t_list *lst);
char	verif_digits(int count, char **strs);
t_bool	verif_limits(char **strs);
t_bool	verif_sim(int *tab, t_stack **a);
t_bool	param_is_valid(char *str);
void	free_stack(t_stack **stack);
void	push_exit(t_stack **stack_a, t_stack **stack_b, t_error error);
t_bool	push_init_ret(int count, char **strs, t_stack **a, t_stack **b);

#endif
