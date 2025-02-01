/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:40:32 by dayano            #+#    #+#             */
/*   Updated: 2025/01/23 16:25:12 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_str(char **lst_str)
{
	char	*tmp;

	if (!lst_str)
		return ;
	while (*lst_str)
	{
		tmp = *lst_str;
		lst_str++;
		free(tmp);
	}
	*lst_str = NULL;
}

void	ft_free_stack(t_stack **stack_a)
{
	t_stack	*stack_tmp;

	while (*stack_a)
	{
		stack_tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(stack_tmp);
	}
	stack_a = NULL;
}
