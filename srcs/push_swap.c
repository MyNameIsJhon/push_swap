/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:37:23 by jriga             #+#    #+#             */
/*   Updated: 2025/09/04 01:32:26 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>
#include <limits.h>

t_bool	stack_index(t_stack **stack)
{
	int		*index;
	size_t	size;

	size = (*stack)->size;
	index = (int *)malloc(sizeof(int) * (size + 1));
	if (!index)
		return (FALSE);
	fill_index(index, (*stack)->lst);
	quick_sort(index, 0, size - 1);
	if (verif_sim(index, stack) == FALSE)
	{
		free(index);
		return (FALSE);
	}
	assign_indices((*stack)->lst, index, size);
	free(index);
	return (TRUE);
}

void	push_init(int count, char **strs, t_stack **a, t_stack **b)
{
	if (count == 0)
		push_exit(NULL, NULL, NONE);
	if (!verif_digits(count, strs) || !verif_limits(strs))
		push_exit(NULL, NULL, INPUT_ERROR);
	if (count == 1)
		push_exit(NULL, NULL, NONE);
	*a = malloc(sizeof(t_stack));
	*b = malloc(sizeof(t_stack));
	if (!a || !b)
		push_exit(a, b, MEMORY_ERROR);
	(*a)->lst = stack_init(count, strs);
	(*a)->size = ft_lstsize((*a)->lst);
	(*a)->name = 'a';
	(*b)->name = 'b';
	(*b)->size = 0;
	(*b)->lst = NULL;
	if (!stack_index(a))
		push_exit(a, b, INPUT_ERROR);
	if (verif_order((*a)->lst))
		push_exit(a, b, NONE);
}

t_bool	push_init_ret(int count, char **strs, t_stack **a, t_stack **b)
{
	if (count == 0)
		return (FALSE);
	if (!verif_digits(count, strs) || !verif_limits(strs))
		return (FALSE);
	if (count == 1)
		return (FALSE);
	*a = malloc(sizeof(t_stack));
	*b = malloc(sizeof(t_stack));
	if (!a || !b)
		return (FALSE);
	(*a)->lst = stack_init(count, strs);
	(*a)->size = ft_lstsize((*a)->lst);
	(*a)->name = 'a';
	(*b)->name = 'b';
	(*b)->size = 0;
	(*b)->lst = NULL;
	if (!stack_index(a))
		return (FALSE);
	return (TRUE);
}

void	args_init(int argc, char **argv, t_stack **a, t_stack **b)
{
	int		params_c;
	char	**srcs;

	if (argc == 2)
	{
		params_c = count_params(argv[1]);
		if (params_c == 1 && param_is_valid(argv[1]))
			push_exit(NULL, NULL, NONE);
		else if (params_c == 1 || params_c == 0)
			push_exit(NULL, NULL, INPUT_ERROR);
		srcs = ft_split(argv[1], ' ');
		if (!push_init_ret(ft_strslen(srcs), srcs, a, b))
		{
			ft_strsfree(srcs);
			push_exit(a, b, INPUT_ERROR);
		}
		if (verif_order((*a)->lst))
		{
			ft_strsfree(srcs);
			push_exit(a, b, NONE);
		}
		ft_strsfree(srcs);
	}
	else
		push_init(argc - 1, argv + 1, a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	args_init(argc, argv, &stack_a, &stack_b);
	pushswap_algo(stack_a, stack_b);
	push_exit(&stack_a, &stack_b, NONE);
	return (0);
}
