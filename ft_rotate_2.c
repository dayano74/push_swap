/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:49:45 by dayano            #+#    #+#             */
/*   Updated: 2025/02/01 14:50:02 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rorate_rr(t_stack **stack_a, t_stack **stack_b, int cost_a,
		int cost_b)
{
	int	cost_same;
	int	remained_cost_a;
	int	remained_cost_b;

	if (cost_a < cost_b)
		cost_same = cost_a;
	else
		cost_same = cost_b;
	remained_cost_a = cost_a - cost_same;
	remained_cost_b = cost_b - cost_same;
	while (cost_same)
	{
		ft_rr(stack_a, stack_b);
		cost_same--;
	}
	ft_rotate_stack(stack_a, remained_cost_a, ft_ra, ft_rra);
	ft_rotate_stack(stack_b, remained_cost_b, ft_rb, ft_rrb);
}

void	ft_rorate_rrr(t_stack **stack_a, t_stack **stack_b, int cost_a,
		int cost_b)
{
	int	cost_same;
	int	remained_cost_a;
	int	remained_cost_b;

	if (abs(cost_a) < abs(cost_b))
		cost_same = abs(cost_a);
	else
		cost_same = abs(cost_b);
	remained_cost_a = abs(cost_a) - cost_same;
	remained_cost_b = abs(cost_b) - cost_same;
	while (cost_same)
	{
		ft_rrr(stack_a, stack_b);
		cost_same--;
	}
	ft_rotate_stack(stack_a, -remained_cost_a, ft_ra, ft_rra);
	ft_rotate_stack(stack_b, -remained_cost_b, ft_rb, ft_rrb);
}
