/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 01:47:10 by jriga             #+#    #+#             */
/*   Updated: 2025/08/16 14:21:36 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

static void	dir_apply_common(int *dir, t_dir *a, t_dir *b)
{
	while (a->dir && b->dir && (ft_sgn(b->dir) == ft_sgn(a->dir)))
	{
		if (a->dir > 0 && b->dir > 0)
		{
			a->dir--;
			b->dir--;
			dir[0]++;
		}
		else if (a->dir < 0 && b->dir < 0)
		{
			a->dir++;
			b->dir++;
			dir[1]++;
		}
		else
			break ;
	}
}

static void	dir_apply_single(int *dst_rr_rb, int *dst_rrr_rrb, int *val)
{
	while (*val)
	{
		if (*val > 0)
		{
			(*dst_rr_rb)++;
			(*val)--;
		}
		else
		{
			(*dst_rrr_rrb)++;
			(*val)++;
		}
	}
}

void	dir_to_instructs(int *dir, t_dir a, t_dir b)
{
	dir_apply_common(dir, &a, &b);
	dir_apply_single(&dir[2], &dir[3], &a.dir);
	dir_apply_single(&dir[4], &dir[5], &b.dir);
}

void	instructs_action(t_stack *a, t_stack *b, int *instructs)
{
	int inst[6];

	ft_memcpy(inst, instructs, sizeof(int) * 6);
	while (inst[0]-- > 0)
		rotate_all(a, b);
	while (inst[1]-- > 0)
		rrotate_all(a, b);
	while (inst[2]-- > 0)
		rotate(a, TRUE);
	while (inst[3]-- > 0)
		rrotate(a, TRUE);
	while (inst[4]-- > 0)
		rotate(b, TRUE);
	while (inst[5]-- > 0)
		rrotate(b, TRUE);
}

t_dir	find_best_dir_u(t_stack *a, t_stack *b, int *instructs)
{
	t_dir	best[2];
	int		cost;
	int		min_cost;
	int		i;
	t_dir	b_inf;

	cost = -1;
	i = 0;
	min_cost = INT_MAX;
	while (i < (int)a->size)
	{
		b_inf = find_dir_inferior(a->dir[i].index, b->dir, b->size);
		cost = calculate_cost(a->dir[i], b_inf);
		if (cost < min_cost)
		{
			min_cost = cost;
			best[0] = a->dir[i];
			best[1] = b_inf;
		}
		i++;
	}
	dir_to_instructs(instructs, best[0], best[1]);
	return (best[0]);
}
