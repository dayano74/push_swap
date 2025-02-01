/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:31:18 by dayano            #+#    #+#             */
/*   Updated: 2025/02/01 21:25:36 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*stack_tmp;

	stack_tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	stack_tmp->next = *stack_b;
	*stack_b = stack_tmp;
	write(1, "pb\n", 3);
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*stack_tmp;

	stack_tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	stack_tmp->next = *stack_a;
	*stack_a = stack_tmp;
	write(1, "pa\n", 3);
}
