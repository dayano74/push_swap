/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:23:31 by dayano            #+#    #+#             */
/*   Updated: 2025/01/24 11:14:19 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_ra(t_stack **stack_a)
{
	ft_sa(stack_a);
	ft_ra(stack_a);
}

void	ft_sa_rra(t_stack **stack_a)
{
	ft_sa(stack_a);
	ft_rra(stack_a);
}

void	ft_sa(t_stack **stack_a)
{
	t_stack	*stack_tmp;

	if (!*stack_a)
		return ;
	stack_tmp = (*stack_a)->next;
	(*stack_a)->next = stack_tmp->next;
	stack_tmp->next = (*stack_a);
	*stack_a = stack_tmp;
	write(1, "sa\n", 3);
}

void	ft_ra(t_stack **stack_a)
{
	t_stack	*stack_a_top;

	stack_a_top = malloc(sizeof(t_stack));
	if (!stack_a_top)
		return ;
	stack_a_top->nbr = (*stack_a)->nbr;
	stack_a_top->next = NULL;
	*stack_a = (*stack_a)->next;
	ft_ps_lstadd_back(stack_a, stack_a_top);
	write(1, "ra\n", 3);
}

void	ft_rra(t_stack **stack_a)
{
	t_stack	*stack_a_last;
	t_stack	*stack_a_prevlast;

	stack_a_prevlast = *stack_a;
	while (stack_a_prevlast->next->next)
		stack_a_prevlast = stack_a_prevlast->next;
	stack_a_last = stack_a_prevlast->next;
	stack_a_prevlast->next = NULL;
	stack_a_last->next = *stack_a;
	*stack_a = stack_a_last;
	write(1, "rra\n", 4);
}
