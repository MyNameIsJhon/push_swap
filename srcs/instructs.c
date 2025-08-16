/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:46:32 by jriga             #+#    #+#             */
/*   Updated: 2025/08/16 11:52:12 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	swap(t_stack *stack, t_bool print)
{
	t_list	*ptr;
	t_list	*lst;

	lst = stack->lst;
	if (!lst || !lst->next)
		return ;
	ptr = lst->next;
	lst->next = ptr->next;
	ptr->next = lst;
	stack->lst = ptr;
	if (print)
		ft_printf("s%c\n", stack->name);
}

void	push(t_stack *from, t_stack *to)
{
	t_list	*ptr;

	if (!from || !from->lst || !to)
		return ;
	ptr = from->lst;
	from->lst = from->lst->next;
	ptr->next = to->lst;
	to->lst = ptr;
	from->size--;
	to->size++;
	if (from->size == 0)
		from->lst = NULL;
	ft_printf("p%c\n", to->name);
}

void	rotate(t_stack *stack, t_bool print)
{
	t_list	*ptr;

	ptr = stack->lst;
	if (!ptr || !ptr->next)
		return ;
	stack->lst = ptr->next;
	ptr->next = NULL;
	ft_lstadd_back(&stack->lst, ptr);
	if (print)
		ft_printf("r%c\n", stack->name);
}

void	rrotate(t_stack *stack, t_bool print)
{
	t_list	*ptr;
	t_list	*last;

	ptr = stack->lst;
	if (!ptr || !ptr->next)
		return ;
	while (ptr->next->next)
		ptr = ptr->next;
	last = ft_lstlast(stack->lst);
	ptr->next = NULL;
	last->next = stack->lst;
	stack->lst = last;
	if (print)
		ft_printf("rr%c\n", stack->name);
}
/* void push(t_list **stack_a, t_list **stack_b) */
/* { */
/* 	t_list *ptr; */
/**/
/* 	if  */
/* } */
