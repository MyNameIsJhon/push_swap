/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:37:23 by jriga             #+#    #+#             */
/*   Updated: 2025/09/04 01:32:26 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>
#include <limits.h>

int	main(int argc, char **argv)
{
	char	**srcs;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		params_c;

	if (argc == 2)
	{
		params_c = count_params(argv[1]);
		if (params_c == 0)
			push_exit(NULL, NULL, INPUT_ERROR);
		else if (params_c == 1 && param_is_valid(argv[1]))
			push_exit(NULL, NULL, NONE);
		else if (params_c == 1)
			push_exit(NULL, NULL, INPUT_ERROR);
		srcs = ft_split(argv[1], ' ');
		push_init(ft_strslen(srcs), srcs, &stack_a, &stack_b);
		ft_strsfree(srcs);
	}
	else
		push_init(argc - 1, argv + 1, &stack_a, &stack_b);
	pushswap_algo(stack_a, stack_b);
	push_exit(&stack_a, &stack_b, NONE);
	return (0);
}
