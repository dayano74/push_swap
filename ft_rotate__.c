/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:39:36 by dayano            #+#    #+#             */
/*   Updated: 2025/01/30 14:07:12 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_ascending(t_stack **stack_a)
{
	t_stack	*min_a;
	int		size_a;

	size_a = ft_ps_lstsize(*stack_a);
	ft_assign_index_for_accending(stack_a);
	min_a = ft_get_min_node(*stack_a);
	if (min_a->idx > size_a / 2)
	{
		while (size_a - min_a->idx)
		{
			ft_rra(stack_a);
			min_a->idx++;
		}
	}
	else
	{
		while (min_a->idx)
		{
			ft_ra(stack_a);
			min_a->idx--;
		}
	}
}

t_stack	*ft_rotate_min(t_stack **stack_a, int min_idx, int size_a)
{
	// printf("max_idx = %d, size_a = %d\n", min_idx, size_a);
	if (min_idx > size_a / 2)
	{
		min_idx--;
		while (size_a - min_idx)
		{
			ft_rra(stack_a);
			min_idx++;
		}
	}
	else
	{
		min_idx--;
		while (min_idx)
		{
			ft_ra(stack_a);
			min_idx--;
		}
	}
	return (*stack_a);
}

// t_stack	*ft_rotate_max(t_stack **stack_a, int max_idx, int size_a)
// {
// 	if (max_idx > size_a / 2)
// 	{
// 		while (size_a - max_idx)
// 		{
// 			ft_rra(stack_a);
// 			max_idx++;
// 		}
// 	}
// 	else if (max_idx < size_a / 2)
// 	{
// 		while (max_idx)
// 		{
// 			ft_ra(stack_a);
// 			max_idx--;
// 		}
// 	}
// 	return (*stack_a);
// }

void	ft_select_rotate(t_stack **stack_a, t_stack *stack_a_target)
{
	int	size_a;

	size_a = ft_ps_lstsize(*stack_a);
	if (stack_a_target->idx > size_a / 2)
	{
		while (size_a - (stack_a_target->idx))
		{
			ft_rra(stack_a);
			(stack_a_target->idx)++;
		}
	}
	else
	{
		while (stack_a_target->idx)
		{
			ft_ra(stack_a);
			(stack_a_target->idx)--;
		}
	}
}

void	ft_rotate_old(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*stack_a_target;
	int		flg;

	flg = 0;
	ft_assign_index(stack_a);
	stack_a_target = ft_find_target(stack_a, *stack_b, &flg);
	if (flg)
	{
		// printf("used flag!\n");
		return ;
	}
	ft_select_rotate(stack_a, stack_a_target);
}
