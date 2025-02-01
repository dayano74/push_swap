/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:59:02 by dayano            #+#    #+#             */
/*   Updated: 2025/01/30 15:22:31 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_get_min_node(t_stack *stack_a)
{
	t_stack	*min_a;

	min_a = stack_a;
	while (stack_a)
	{
		if (stack_a->nbr < min_a->nbr)
			min_a = stack_a;
		stack_a = stack_a->next;
	}
	return (min_a);
}

t_stack	*ft_get_max_node(t_stack *stack_a)
{
	t_stack	*max_a;

	max_a = stack_a;
	while (stack_a)
	{
		if (stack_a->nbr > max_a->nbr)
			max_a = stack_a;
		stack_a = stack_a->next;
	}
	return (max_a);
}

t_stack	*ft_find_target(t_stack **stack_a, t_stack *stack_b, int *flg)
{
	t_stack	*max_a;
	t_stack	*min_a;
	int		size_a;
	t_stack	*stack_cpy;

	stack_cpy = *stack_a;
	size_a = ft_ps_lstsize(*stack_a);
	min_a = ft_get_min_node(*stack_a);
	// ft_print_stack(*stack_a);
	// printf("stack_b->nbr = %d\n", stack_b->nbr);
	if ((stack_b->nbr) < (min_a->nbr))
	{
		*flg = 1;
		// printf("ft_find_target exception 1\n");
		if (min_a->idx == 1)
			return (*stack_a);
		return (ft_rotate_min(stack_a, min_a->idx, size_a));
	}
	max_a = ft_get_max_node(*stack_a);
	if ((stack_b->nbr) > (max_a->nbr))
	{
		*flg = 1;
		// printf("ft_find_target exception 2\n");
		if (min_a->idx == 1)
			return (*stack_a);
		return (ft_rotate_min(stack_a, min_a->idx, size_a));
	}
	// printf("ft_find_target basicly\n");
	while (stack_cpy->next)
	{
		if ((stack_b->nbr) > (stack_cpy->nbr)
			&& (stack_b->nbr) < (stack_cpy->next->nbr))
			break ;
		stack_cpy = stack_cpy->next;
	}
	return (stack_cpy);
}

void	ft_assign_index(t_stack **stack_a)
{
	t_stack	*stack_tmp;
	int		i;

	i = 0;
	stack_tmp = *stack_a;
	while (stack_tmp)
	{
		stack_tmp->idx = i;
		stack_tmp = stack_tmp->next;
		i++;
	}
}

void	ft_assign_index_for_accending(t_stack **stack_a)
{
	t_stack	*stack_tmp;
	int		i;

	i = 0;
	stack_tmp = *stack_a;
	while (stack_tmp)
	{
		stack_tmp->idx = i;
		stack_tmp = stack_tmp->next;
		i++;
	}
}
