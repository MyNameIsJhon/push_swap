/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:04:38 by jriga             #+#    #+#             */
/*   Updated: 2025/09/04 01:14:39 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	count_in_chunk(t_stack *a, int low, int high)
{
	t_list	*tmp;
	int		count;

	tmp = a->lst;
	count = 0;
	while (tmp)
	{
		if (tmp->index >= low && tmp->index <= high)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

t_dir	find_dir_inferior(int index, t_dir *dir, int size)
{
	int		i;
	t_dir	inf;

	i = 0;
	inf.index = -1;
	inf.dir = 0;
	inf.cost = 0;
	while (i < size)
	{
		if (dir[i].index < index && dir[i].index > inf.index)
			inf = dir[i];
		i++;
	}
	return (inf);
}

int	calculate_cost(t_dir a, t_dir b)
{
	int	a_sign;
	int	b_sign;

	a_sign = ft_sgn(a.dir);
	b_sign = ft_sgn(b.dir);
	if (a_sign == b_sign)
		return (ft_max(ft_abs(a.dir), ft_abs(b.dir)));
	else
		return (ft_abs(a.dir) + ft_abs(b.dir));
}

void	stack_index(t_stack **stack, t_stack **stack_to_free)
{
	int		*index;
	t_list	*lst;
	size_t	i;

	index = (int *)malloc(sizeof(int) * ((*stack)->size + 1));
	if (!index)
		return ;
	i = 0;
	lst = (*stack)->lst;
	while (lst)
	{
		index[i++] = lst->u_ctt.i;
		lst = lst->next;
	}
	quick_sort(index, 0, (*stack)->size - 1);
	verif_sim(index, stack, stack_to_free);
	lst = (*stack)->lst;
	while (lst)
	{
		lst->index = binary_search(index, (*stack)->size, lst->u_ctt.i);
		lst = lst->next;
	}
	free(index);
}
