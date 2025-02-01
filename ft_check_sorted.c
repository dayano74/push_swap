/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:26:26 by dayano            #+#    #+#             */
/*   Updated: 2025/01/24 19:07:18 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sorted(t_stack *stack_a)
{
	t_stack	*stack_copy;

	while (stack_a)
	{
		stack_copy = stack_a->next;
		while (stack_copy)
		{
			if ((stack_a->nbr) > (stack_copy->nbr))
				return (0);
			stack_copy = stack_copy->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}
