/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:38:58 by dayano            #+#    #+#             */
/*   Updated: 2025/02/01 15:33:45 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_ps_lstnew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
	{
		// need func that makes free stacks
		// i think ft_print_error() is not good in this case
		// because cant free stack made before.
		return (NULL);
	}
	new->nbr = content;
	new->next = NULL;
	return (new);
}

void	ft_ps_lstadd_back(t_stack **stack_a, t_stack *stack_new)
{
	if (!stack_a)
		return ;
	if (!*stack_a)
		*stack_a = stack_new;
	else
		(ft_ps_lstlast(*stack_a))->next = stack_new;
}

t_stack	*ft_ps_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_ps_lstsize(t_stack *stack_a)
{
	int size;

	size = 0;
	while (stack_a)
	{
		stack_a = stack_a->next;
		size++;
	}
	return (size);
}
