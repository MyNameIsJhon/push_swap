/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:14:41 by jriga             #+#    #+#             */
/*   Updated: 2025/09/04 01:32:33 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>
#include <limits.h>

void	free_stack(t_stack **stack)
{
	if (*stack)
	{
		if ((*stack)->lst)
			ft_lstclear(&(*stack)->lst, free);
		free(*stack);
		*stack = NULL;
	}
}

t_list	*stack_init(int count, char **strs)
{
	t_list	*lst;
	int		i;

	if (count < 2)
		return (NULL);
	lst = ft_lstnew_i(ft_atoi(strs[0]));
	i = 1;
	lst->index = i - 1;
	if (!lst)
		return (NULL);
	while (i < count)
		ft_lstadd_back(&lst, ft_lstnew_i(ft_atoi(strs[i++])));
	return (lst);
}

static int	fill_dir(t_list *lst, t_dir *dir, int size, int range[2])
{
	int	i;
	int	pos;
	int	d;

	i = 0;
	pos = 0;
	while (lst)
	{
		if (lst->index >= range[0] && lst->index <= range[1])
		{
			if (pos < size / 2)
				d = pos;
			else
				d = -(size - pos);
			dir[i].index = lst->index;
			dir[i].dir = d;
			dir[i].cost = ft_abs(d);
			i++;
		}
		lst = lst->next;
		pos++;
	}
	return (i);
}

t_dir	*dir_init(t_stack *stack, int index_min, int index_max)
{
	t_dir	*dir;
	int		range[2];
	int		max;
	int		alloc_sz;
	int		n;

	max = count_in_chunk(stack, index_min, index_max + 2);
	alloc_sz = max;
	if (alloc_sz < 1)
		alloc_sz = 1;
	dir = (t_dir *)malloc(sizeof(t_dir) * alloc_sz);
	if (!dir)
		return (NULL);
	range[0] = index_min;
	range[1] = index_max;
	n = fill_dir(stack->lst, dir, (int)stack->size, range);
	if (n > 1)
		quick_sort_d(dir, 0, n - 1);
	return (dir);
}

t_bool	param_is_valid(char *str)
{
	long	num;

	if (!ft_strisdigit(str))
		return (FALSE);
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (FALSE);
	return (TRUE);
}
