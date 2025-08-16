/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructs_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:14:35 by jriga             #+#    #+#             */
/*   Updated: 2025/08/16 11:49:53 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_all(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	rotate(stack_a, FALSE);
	rotate(stack_b, FALSE);
	ft_putstr("rr\n");
}

void	rrotate_all(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	rrotate(stack_a, FALSE);
	rrotate(stack_b, FALSE);
	ft_putstr("rrr\n");
}

void	swap_all(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	swap(stack_a, FALSE);
	swap(stack_b, FALSE);
	ft_putstr("ss\n");
}
