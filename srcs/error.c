/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 01:01:50 by jriga             #+#    #+#             */
/*   Updated: 2025/09/04 01:11:31 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <limits.h>

t_bool	ft_strhasdigit(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str++))
			return (TRUE);
	}
	return (FALSE);
}

t_bool	verif_limits(char **strs)
{
	long	num;

	if (!strs)
		return (FALSE);
	num = ft_atol(*strs++);
	if (num < INT_MIN || num > INT_MAX)
		return (FALSE);
	while (*strs)
	{
		num = ft_atol(*strs);
		if (num < INT_MIN || num > INT_MAX)
			return (FALSE);
		strs++;
	}
	return (TRUE);
}

char	verif_digits(int count, char **strs)
{
	int	i;

	i = 0;
	if (count < 2)
		return (0);
	while (strs[i])
	{
		if (!ft_strisdigit(strs[i++]))
			return (0);
	}
	return (1);
}

t_bool	verif_order(t_list *lst)
{
	if (lst == NULL)
		return (TRUE);
	if (lst && !lst->next)
		return (TRUE);
	while (lst->next)
	{
		if (lst->index > lst->next->index)
			return (FALSE);
		lst = lst->next;
	}
	return (TRUE);
}

t_bool	verif_sim(int *tab, t_stack **a)
{
	int	i;

	i = 0;
	while (i < (int)(*a)->size - 1)
	{
		if (tab[i] == tab[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}
