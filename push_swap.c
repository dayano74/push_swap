/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:49:57 by dayano            #+#    #+#             */
/*   Updated: 2025/02/01 21:53:29 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_process_three(t_stack **stack_a)
{
	t_stack	*stack_a_2nd;
	t_stack	*stack_a_3rd;

	stack_a_2nd = (*stack_a)->next;
	stack_a_3rd = stack_a_2nd->next;
	if (ft_check_sorted(*stack_a))
		return ; // need?
	if (((*stack_a)->nbr) < (stack_a_2nd->nbr))
	{
		if (((*stack_a)->nbr) < (stack_a_3rd->nbr))
			ft_sa_ra(stack_a);
		else
			ft_rra(stack_a);
	}
	else
	{
		if ((stack_a_2nd->nbr) < (stack_a_3rd->nbr))
		{
			if (((*stack_a)->nbr) < (stack_a_3rd->nbr))
				ft_sa(stack_a);
			else
				ft_ra(stack_a);
		}
		else
			ft_sa_rra(stack_a);
	}
}

void	ft_pb_until_three(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_ps_lstsize(*stack_a);
	size_b = 0;
	while (size_a >= 4 && size_b <= 2)
	{
		ft_pb(stack_a, stack_b);
		size_b++;
	}
	if (size_a == 3)
		return ;
	while (size_a >= 4)
	{
		ft_rotate_optimal(stack_a, stack_b, ft_calculate_cost_atob);
		ft_pb(stack_a, stack_b);
		size_a--;
	}
}

void	ft_pa_all_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size_b;

	size_b = ft_ps_lstsize(*stack_b);
	while (size_b > 0)
	{
		ft_rotate_optimal(stack_b, stack_a, ft_calculate_cost_btoa);
		ft_pa(stack_a, stack_b);
		size_b--;
	}
}

void	ft_process_over_three(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		size_b;

	stack_b = NULL;
	ft_pb_until_three(stack_a, &stack_b);
	ft_process_three(stack_a);
	ft_pa_all_stack_b(stack_a, &stack_b);
	ft_rotate_ascending(stack_a); // func name should change ft_rotate_sorted()
}

void	ft_sort_with_turk(t_stack **stack_a)
{
	int	stack_size;

	stack_size = ft_ps_lstsize(*stack_a);
	if (stack_size == 2)
		ft_sa(stack_a);
	else if (stack_size == 3)
		ft_process_three(stack_a);
	else
		ft_process_over_three(stack_a);
}
