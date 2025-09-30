/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 22:09:11 by jriga             #+#    #+#             */
/*   Updated: 2025/09/04 01:33:09 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

void	push_exit(t_stack **stack_a, t_stack **stack_b, t_error error)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	if (error != NONE)
	{
		ft_puterror("Error\n");
		exit(1);
	}
	exit(0);
}

static int	find_pos(t_list *lst, int index)
{
	int	i;

	i = 0;
	while (lst && lst->index != index)
	{
		lst = lst->next;
		i++;
	}
	if (!lst)
		return (-1);
	return (i);
}

static void	align_top(t_stack *a, int pos)
{
	int	i;

	if (pos <= (int)a->size / 2)
	{
		i = pos;
		while (i-- > 0)
			rotate(a, TRUE);
	}
	else
	{
		i = a->size - pos;
		while (i-- > 0)
			rrotate(a, TRUE);
	}
}

int	push_index(t_stack *a, t_stack *b, int index)
{
	int	pos;

	pos = find_pos(a->lst, index);
	if (pos < 0)
		return (0);
	align_top(a, pos);
	push(a, b);
	return (b->lst->index);
}
