/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:26:38 by jriga             #+#    #+#             */
/*   Updated: 2025/08/07 21:36:35 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void test_dir(t_stack *a, t_stack *b)
{
	t_dir *dir_a;
	int		i;
	(void)b;

	dir_a = dir_init(a, 0, 20);
	i = 20;
	while (i--)
	{
		ft_printf("Index: %d, Dir: %d, Cost: %d\n", dir_a[i].index, dir_a[i].dir, dir_a[i].cost);
	}	
}

void print_instructs(int *instructs)
{
	int i;

	i = 0;
	while (i < 6)
	{
		ft_printf("Instructs[%d]: %d\n", i, instructs[i]);
		i++;
	}
}
