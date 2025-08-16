/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:37:23 by jriga             #+#    #+#             */
/*   Updated: 2025/08/16 14:24:55 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>
#include <limits.h>

t_dir	*dir_init(t_stack *stack, int index_min, int index_max)
{
	t_dir	*dir;
	t_list	*lst;
	int		i;
	int		pos;
	int		max;

	max = count_in_chunk(stack, index_min, index_max + 2);
	dir = malloc((max) * (sizeof(t_dir) + 1));
	lst = stack->lst;
	i = 0;
	pos = 0;
	while (lst && i < max)
	{
		if (lst->index >= index_min && lst->index <= index_max)
		{
			dir[i].index = lst->index;
			if (pos < (int)stack->size / 2)
				dir[i].dir = pos;
			else
				dir[i].dir = -((int)stack->size - pos);
			dir[i].cost = ft_abs(dir[i].dir);
			i++;
		}
		lst = lst->next;
		pos++;
	}
	quick_sort_d(dir, 0, i - 1);
	return (dir);
}

int both_path(t_stack *a, t_stack *b, int index_min, int index_max)
{
	int		instructs[6];
	int		count;
	t_dir	*dir_a;
	t_dir	*dir_b;

	count = count_in_chunk(a, index_min, index_max);
	dir_a = dir_init(a, index_min, index_max);
	dir_b = dir_init(b, 0, a->size + b->size);
	a->dir = dir_a;
	b->dir = dir_b;
	ft_bzero(instructs, sizeof(int) * 6);
	if (!dir_a || !dir_b)
	{
		free(dir_a);
		free(dir_b);
		return (-1);
	}
	find_best_dir_u(a, b, instructs);
	instructs_action(a, b, instructs);
	push(a, b);
	free(dir_a);
	free(dir_b);
	return (count);
}

t_bool	ft_strhasdigit(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str++))
			return (TRUE);
	}
	return (FALSE);
}

int	main(int argc, char **argv)
{
	char	**srcs;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		params_c;

	if (argc == 2)
	{
		params_c = count_params(argv[1]);
		if (params_c == 0)
			push_exit(NULL, NULL, INPUT_ERROR);
		if (params_c == 1 && ft_strisdigit(argv[1]))
			push_exit(NULL, NULL, NONE);
		if (params_c == 1 && !ft_strisdigit(argv[1]))
			push_exit(NULL, NULL, INPUT_ERROR);
		srcs = ft_split(argv[1], ' ');
		push_init(ft_strslen(srcs), srcs, &stack_a, &stack_b);
		ft_strsfree(srcs);
	}
	else
		push_init(argc - 1, argv + 1, &stack_a, &stack_b);
	pushswap_algo(stack_a, stack_b);
	push_exit(&stack_a, &stack_b, NONE);
	return (0);
}
