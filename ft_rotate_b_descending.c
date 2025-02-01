/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_b_descending.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:29:23 by dayano            #+#    #+#             */
/*   Updated: 2025/02/01 21:52:01 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_cost(int idx, int stack_size)
{
	if (idx > stack_size / 2)
		return (idx - stack_size);
	else
		return (idx);
}

int	ft_get_total_cost(int cost_a, int cost_b)
{
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
	{
		if (abs(cost_a) > abs(cost_b))
			return (abs(cost_a));
		else
			return (abs(cost_b));
	}
	else
		return (abs(cost_a) + abs(cost_b));
}

t_stack	*ft_get_b_target(t_stack **stack_b, int current_nbr)
{
	t_stack	*b_target;
	t_stack	*tmp;
	t_stack	*max_node;
	t_stack	*min_node;

	ft_assign_index(*stack_b);
	b_target = *stack_b;
	tmp = *stack_b;
	max_node = ft_get_max_node(*stack_b);
	min_node = ft_get_min_node(*stack_b);
	if (current_nbr > max_node->nbr || current_nbr < min_node->nbr)
		b_target = max_node;
	else
	{
		while (tmp && tmp->next)
		{
			if (current_nbr < tmp->nbr && current_nbr > tmp->next->nbr)
			{
				b_target = tmp->next;
				break ;
			}
			tmp = tmp->next;
		}
	}
	return (b_target);
}

int	ft_calculate_cost_atob(t_stack **stack_b, t_stack *current_a, int size_a)
{
	t_stack	*b_target;
	int		cost_a;
	int		cost_b;
	int		size_b;

	cost_a = ft_get_cost(current_a->idx, size_a);
	size_b = ft_ps_lstsize(*stack_b);
	b_target = ft_get_b_target(stack_b, current_a->nbr);
	cost_b = ft_get_cost(b_target->idx, size_b);
	return (ft_get_total_cost(cost_a, cost_b));
}

// void	ft_rotate_b_descending(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	*a_current;
// 	t_stack	*min_cost_node;
// 	int		size_a;

// 	size_a = ft_ps_lstsize(*stack_a);
// 	ft_assign_index(stack_a);
// 	a_current = *stack_a;
// 	min_cost_node = *stack_a;
// 	min_cost_node->cost = ft_calculate_cost(stack_b, a_current, size_a);
// 	a_current->cost = min_cost_node->cost;
// 	while (a_current)
// 	{
// 		a_current->cost = ft_calculate_cost(stack_b, a_current, size_a);
// 		if (min_cost_node->cost > a_current->cost)
// 			min_cost_node = a_current;
// 		a_current = a_current->next;
// 	}
// 	ft_rotate_b(stack_a, stack_b, min_cost_node->cost, size_a);
// }

void	ft_rotate_optimal(t_stack **push_stack, t_stack **receive_stack,
		int (*calculate_cost)(t_stack **, t_stack *, int))
{
	t_stack	*current;
	t_stack	*min_cost_pnode;
	int		stack_size;

	stack_size = ft_ps_lstsize(*receive_stack);
	ft_assign_index(receive_stack);
	current = *receive_stack;
	min_cost_pnode = current;
	min_cost_pnode->cost = calculate_cost(push_stack, current, stack_size);
	while (current)
	{
		current->cost = calculate_cost(push_stack, current, stack_size);
		if (min_cost_pnode->cost > current->cost)
			min_cost_pnode = current;
		current = current->next;
	}
	ft_rotate_stacks(push_stack, receive_stack, min_cost_pnode->idx,
		stack_size);
}
