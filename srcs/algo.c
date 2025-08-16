/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:30:48 by jriga             #+#    #+#             */
/*   Updated: 2025/08/10 19:16:36 by jriga            ###   ########.fr       */
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
			both_path(stack_a, stack_b, 0,
				stack_a->size + stack_b->size - 1);
		while (stack_b->lst)
			push_index(stack_b, stack_a, stack_b->size - 1);
	}
}
