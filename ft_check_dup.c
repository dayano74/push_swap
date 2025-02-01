/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:41:55 by dayano            #+#    #+#             */
/*   Updated: 2025/01/23 16:00:44 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_dup(t_stack *a)
{
	t_stack	*copy;

	while (a)
	{
		copy = a->next;
		while (copy)
		{
			if (a->nbr == copy->nbr)
				return (1);
			copy = copy->next;
		}
		a = a->next;
	}
	return (0);
}
