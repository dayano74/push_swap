/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:44:00 by dayano            #+#    #+#             */
/*   Updated: 2025/02/01 13:46:23 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_stack **stack_b)
{
	t_stack	*stack_b_top;

	stack_b_top = malloc(sizeof(t_stack));
	if (!stack_b_top)
		return ;
	stack_b_top->nbr = (*stack_b)->nbr;
	stack_b_top->next = NULL;
	*stack_b = (*stack_b)->next;
	ft_ps_lstadd_back(stack_b, stack_b_top);
	write(1, "rb\n", 3);
}

void	ft_rrb(t_stack **stack_b)
{
	t_stack	*stack_b_last;
	t_stack	*stack_b_prevlast;

	stack_b_prevlast = *stack_b;
	while (stack_b_prevlast->next->next)
		stack_b_prevlast = stack_b_prevlast->next;
	stack_b_last = stack_b_prevlast->next;
	stack_b_prevlast->next = NULL;
	stack_b_last->next = *stack_b;
	*stack_b = stack_b_last;
	write(1, "rrb\n", 4);
}
