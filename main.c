/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:40:29 by dayano            #+#    #+#             */
/*   Updated: 2025/01/26 21:25:09 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	int	i;

	i = 1;
	while (stack)
	{
		printf("[%d] -> %d\n", i, stack->nbr);
		stack = stack->next;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = ft_check_args(argc, argv);
	// ft_print_stack(a); // del before defence
	if (!a || ft_check_dup(a))
	{
		ft_free_stack(&a);
		ft_print_error();
	}
	if (!ft_check_sorted(a))
		ft_sort_with_turk(&a);
	// else
	// 	printf("already sorted!\n");
	// ft_print_stack(a); // del before defence
	ft_free_stack(&a);
	return (0);
}
