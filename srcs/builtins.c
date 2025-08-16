/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 20:57:41 by jriga             #+#    #+#             */
/*   Updated: 2025/08/16 14:20:09 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

void	push_init(int count, char **strs, t_stack **stack_a, t_stack **stack_b)
{
	if (count == 0)
		push_exit(NULL, NULL, NONE);
	if (!verif_digits(count, strs))
		push_exit(NULL, NULL, INPUT_ERROR);
	if (count == 1)
		push_exit(NULL, NULL, NONE);
	*stack_a = malloc(sizeof(t_stack));
	*stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		push_exit(stack_a, stack_b, MEMORY_ERROR);
	(*stack_a)->lst = stack_init(count, strs);
	(*stack_a)->size = ft_lstsize((*stack_a)->lst);
	(*stack_a)->name = 'a';
	(*stack_b)->name = 'b';
	(*stack_b)->size = 0;
	(*stack_b)->lst = NULL;
	stack_index(stack_a, stack_b);
	if (verif_order((*stack_a)->lst))
		push_exit(NULL, NULL, NONE);
}

int	binary_search(int *tab, int size, int nb)
{
	int	low;
	int	high;
	int	mid;

	low = 0;
	high = size - 1;
	mid = (low + high) / 2;
	while (tab[mid] != nb)
	{
		if (low > high)
			return (-1);
		if (tab[mid] < nb)
			low = mid + 1;
		else
			high = mid - 1;
		mid = (low + high) / 2;
	}
	return (mid);
}

t_bool	verif_sim(int *tab, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (i < (int)(*a)->size - 1)
	{
		if (tab[i] == tab[i + 1])
			push_exit(a, b, INPUT_ERROR);
		i++;
	}
	return (TRUE);
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

int	push_index(t_stack *a, t_stack *b, int index)
{
	t_list	*lst;
	int		i;

	lst = a->lst;
	i = 0;
	while (lst)
	{
		if (lst->index == index)
			break ;
		lst = lst->next;
		i++;
	}
	if (!lst)
		return (0);
	if (i <= (int)a->size / 2)
	{
		while (i-- > 0)
			rotate(a, TRUE);
	}
	else
	{
		i = a->size - i;
		while (i-- > 0)
			rrotate(a, TRUE);
	}
	push(a, b);
	return (b->lst->index);
}
