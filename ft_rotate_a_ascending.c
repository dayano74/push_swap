/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_a_ascending.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:16:05 by dayano            #+#    #+#             */
/*   Updated: 2025/02/01 21:52:16 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_get_a_target(t_stack **stack_a, int current_nbr)
{
	t_stack	*a_target;
	t_stack	*tmp;
	t_stack	*max_node;
	t_stack	*min_node;

	ft_assign_index(*stack_a);
	a_target = *stack_a;
	tmp = *stack_a;
	max_node = ft_get_max_node(*stack_a);
	min_node = ft_get_min_node(*stack_a);
	if (current_nbr > max_node->nbr || current_nbr < min_node->nbr)
		a_target = min_node;
	else
	{
		while (tmp && tmp->next)
		{
			if (current_nbr > tmp->nbr && current_nbr < tmp->next->nbr)
			{
				a_target = tmp->next;
				break ;
			}
			tmp = tmp->next;
		}
	}
	return (a_target);
}

int	ft_calculate_cost_btoa(t_stack **stack_a, t_stack *b_current, int size_b)
{
	t_stack	*a_target;
	int		cost_a;
	int		cost_b;
	int		size_a;

	cost_b = ft_get_cost(b_current->idx, size_b);
	size_a = ft_ps_lstsize(*stack_a);
	a_target = ft_get_a_target(stack_a, b_current->nbr);
	cost_a = ft_get_cost(a_target->idx, size_a);
	return (ft_get_total_cost(cost_a, cost_b));
}

// void	ft_rotate_a_ascending(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	*b_current;
// 	t_stack	*min_cost_node;
// 	int		size_b;

// 	size_b = ft_ps_lstsize(*stack_b);
// 	ft_assign_index(stack_b);
// 	b_current = *stack_b;
// 	min_cost_node = *stack_b;
// 	min_cost_node->cost = ft_calculate_cost(stack_a, b_current, size_b);
// 	b_current->cost = min_cost_node->cost;
// 	while (b_current)
// 	{
// 		b_current->cost = ft_calculate_cost(stack_a, b_current, size_b);
// 		if (min_cost_node->cost > b_current->cost)
// 			min_cost_node = b_current;
// 		b_current = b_current->next;
// 	}
// 	ft_rotate_a(stack_a, stack_b, min_cost_node->idx, size_b);
// }

// void	ft_rotate_optimal(t_stack **push_stack, t_stack **receive_stack,
// 		int (*calculate_cost)(t_stack **, t_stack *, int))
// {
// 	t_stack	*current;
// 	t_stack	*min_cost_node;
// 	int		stack_size;

// 	stack_size = ft_ps_lstsize(*receive_stack);
// 	ft_assign_index(receive_stack);
// 	current = *receive_stack;
// 	min_cost_node = current;
// 	min_cost_node->cost = calculate_cost(push_stack, current, stack_size);
// 	while (current)
// 	{
// 		current->cost = calculate_cost(push_stack, current, stack_size);
// 		if (min_cost_node->cost > current->cost)
// 			min_cost_node = current;
// 		current = current->next;
// 	}
// 	ft_rotate_stacks(push_stack, receive_stack, min_cost_node->idx, stack_size);
// }
