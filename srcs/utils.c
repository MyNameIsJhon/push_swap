/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:14:41 by jriga             #+#    #+#             */
/*   Updated: 2025/08/16 13:15:20 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

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

char	verif_digits(int count, char **strs)
{
	int	i;

	i = 1;
	if (count < 2)
		return (0);
	while (strs[i])
	{
		if (!ft_strisdigit(strs[i++]))
			return (0);
	}
	return (1);
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
