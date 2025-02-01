/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:59:51 by dayano            #+#    #+#             */
/*   Updated: 2025/02/01 22:01:09 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_one_stack(t_stack **stack, int cost,
		void (*ft_rotate)(t_stack **), void (*ft_reverse_rotate)(t_stack **))
{
	if (cost > 0)
	{
		while (cost)
		{
			ft_rotate(stack);
			cost--;
		}
	}
	else
	{
		while (cost)
		{
			ft_reverse_rotate(stack);
			cost++;
		}
	}
}

void	ft_simple_rotate(t_stack **stack_a, t_stack **stack_b, int cost_a,
		int cost_b)
{
	ft_rotate_stack(stack_a, cost_a, ft_ra, ft_rra);
	ft_rotate_stack(stack_b, cost_b, ft_rb, ft_rrb);
}

void	ft_try_double_rotate(t_stack **stack_a, t_stack **stack_b, int cost_a,
		int cost_b)
{
	if (cost_a == 0 && cost_b == 0)
		return ;
	if (cost_a > 0 && cost_b > 0)
		ft_rotate_rr(stack_a, stack_b, cost_a, cost_b);
	else if (cost_a < 0 && cost_b < 0)
		ft_rotate_rrr(stack_a, stack_b, cost_a, cost_b);
	else
		ft_simple_rotate(stack_a, stack_b, cost_a, cost_b);
}

// void	ft_rotate_stacks(t_stack **stack_a, t_stack **stack_b, int idx,
// 		int size_a)
// {
// 	t_stack	*a_target;
// 	t_stack	*b_target;
// 	int		cost_a;
// 	int		cost_b;
// 	int		size_b;

// 	cost_a = ft_get_cost(idx, size_a);
// 	size_b = ft_ps_lstsize(*stack_b);
// 	a_target = *stack_a;
// 	while (idx && a_target->next)
// 	{
// 		a_target = a_target->next;
// 		idx--;
// 	}
// 	b_target = ft_get_b_target(stack_b, a_target->nbr);
// 	cost_b = ft_get_cost(b_target, size_b);
// 	ft_try_double_rotate(stack_a, stack_b, cost_a, cost_b);
// }

void	ft_rotate_stacks(t_stack **push_stack, t_stack **receive_stack,
		int pstack_mincost_idx, int pstack_size)
{
	t_stack	*push_target;
	t_stack	*receive_target;
	int		cost_p;
	int		cost_r;
	int		rstack_size;

	cost_p = ft_get_cost(pstack_mincost_idx, pstack_size);
	rstack_size = ft_ps_lstsize(*receive_stack);
	push_target = *push_stack;
	while (pstack_mincost_idx && push_target->next)
	{
		push_target = push_target->next;
		pstack_mincost_idx--;
	}
	receive_target = ft_get_b_target(receive_stack, push_target->nbr);
	cost_r = ft_get_cost(receive_target->idx, rstack_size);
	ft_try_double_rotate(push_stack, receive_stack, cost_p, cost_r);
}
