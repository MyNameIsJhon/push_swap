/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:07:20 by jriga             #+#    #+#             */
/*   Updated: 2025/09/04 01:31:40 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_d(t_dir *a, t_dir *b)
{
	t_dir	temp;

	if (!a || !b)
		return ;
	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition_d(t_dir *tab, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = tab[(low + high) / 2].cost;
	i = low;
	j = high;
	while (i <= j)
	{
		while (tab[i].cost < pivot)
			i++;
		while (tab[j].cost > pivot)
			j--;
		if (i <= j)
		{
			ft_swap_d(&tab[i], &tab[j]);
			i++;
			j--;
		}
	}
	return (i);
}

void	quick_sort_d(t_dir *tab, int low, int high)
{
	int	pi;

	if (!tab || low >= high)
		return ;
	pi = partition_d(tab, low, high);
	quick_sort_d(tab, low, pi - 1);
	quick_sort_d(tab, pi, high);
}
