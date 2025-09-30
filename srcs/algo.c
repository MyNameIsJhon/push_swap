/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:30:48 by jriga             #+#    #+#             */
/*   Updated: 2025/09/04 01:27:37 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <limits.h>

static void	algo_3(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	if (!a || a->size < 3)
		return ;
	x = a->lst->u_ctt.i;
	y = a->lst->next->u_ctt.i;
	z = a->lst->next->next->u_ctt.i;
	if (x > y && y < z && x < z)
		swap(a, TRUE);
	else if (x > y && y > z)
	{
		swap(a, TRUE);
		rrotate(a, TRUE);
	}
	else if (x > y && y < z && x > z)
		rotate(a, TRUE);
	else if (x < y && y > z && x < z)
	{
		swap(a, TRUE);
		rotate(a, TRUE);
	}
	else if (x < y && y > z && x > z)
		rrotate(a, TRUE);
}

static void	algo_small(t_stack *a, t_stack *b)
{
	if (!a || a->size < 2)
		return ;
	if (a->size == 2)
	{
		if (a->lst->u_ctt.i > a->lst->next->u_ctt.i)
			swap(a, TRUE);
		return ;
	}
	if (a->size == 3)
		return (algo_3(a));
	while (a->size > 3)
		push_index(a, b, b->size);
	algo_3(a);
	while (b->lst)
		push_index(b, a, b->size - 1);
}

int	count_algo(t_stack *a, t_stack *b, int index_min, int index_max)
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

void	pushswap_algo(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a)
		return ;
	if (stack_a->size <= 5)
		algo_small(stack_a, stack_b);
	else
	{
		push_index(stack_a, stack_b, 0);
		while (stack_a->lst)
			count_algo(stack_a, stack_b, 0,
				stack_a->size + stack_b->size - 1);
		while (stack_b->lst)
			push_index(stack_b, stack_a, stack_b->size - 1);
	}
}
