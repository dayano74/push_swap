/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:39:32 by dayano            #+#    #+#             */
/*   Updated: 2025/01/24 11:14:16 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ps_atoi(char *str)
{
	long long int	result;
	int				sign;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (!*str)
		ft_print_error();
	result = 0;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0' || sign * result > INT_MAX || sign * result < INT_MIN)
		ft_print_error();
	return (sign * result);
}

t_stack	*ft_check_args_quort(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	a = NULL;
	tmp = ft_split(argv[1], ' ');
	while (tmp[i])
	{
		j = ft_ps_atoi(tmp[i]);
		ft_ps_lstadd_back(&a, ft_ps_lstnew(j));
		i++;
	}
	ft_free_str(tmp);
	free(tmp);
	return (a);
}

t_stack	*ft_check_args(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	a = NULL;
	i = 1;
	if (argc < 2)
		ft_print_error();
	if (argc == 2)
		a = ft_check_args_quort(argv);
	else
	{
		while (i < argc)
		{
			j = ft_ps_atoi(argv[i]);
			ft_ps_lstadd_back(&a, ft_ps_lstnew(j));
			i++;
		}
	}
	return (a);
}
