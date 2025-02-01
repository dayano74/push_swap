/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:21:02 by dayano            #+#    #+#             */
/*   Updated: 2025/02/01 21:57:56 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	int				idx;
	int				cost;
	struct s_stack	*next;
}					t_stack;

void				ft_print_error(void);
t_stack				*ft_check_args(int argc, char **argv);
t_stack				*ft_check_args_quort(char **argv);
int					ft_ps_atoi(char *str);
t_stack				*ft_ps_lstnew(int content);
void				ft_ps_lstadd_back(t_stack **stack_a, t_stack *stack_new);
t_stack				*ft_ps_lstlast(t_stack *lst);
int					ft_check_dup(t_stack *a);
int					ft_check_sorted(t_stack *stack_a);
void				ft_sort_with_turk(t_stack **stack_a);
int					ft_ps_lstsize(t_stack *stack_a);
void				ft_process_three(t_stack **stack_a);
void				ft_process_over_three(t_stack **stack_a);
void				ft_pb_until_three(t_stack **stack_a, t_stack **stack_b);
void				ft_rotate_optimal(t_stack **push_stack,
						t_stack **receive_stack,
						int (*calculate_cost)(t_stack **, t_stack *, int));
void				ft_assign_index(t_stack **stack_a);
int					ft_calculate_cost(t_stack **stack_b, t_stack *current,
						int size_a);
int					ft_calculate_cost_atob(t_stack **stack_b,
						t_stack *current_a, int size_a);
int					ft_calculate_cost_btoa(t_stack **stack_a,
						t_stack *b_current, int size_b);
t_stack				*ft_get_a_target(t_stack **stack_a, int current_nbr);
t_stack				*ft_get_b_target(t_stack **stack_b, int current_nbr);
int					ft_get_cost(int idx, int stack_size);
int					ft_get_total_cost(int cost_a, int cost_b);

void				ft_rotate_stacks(t_stack **push_stack,
						t_stack **receive_stack, int pstack_mincost_idx,
						int pstack_size);
void				ft_try_double_rotate(t_stack **stack_a, t_stack **stack_b,
						int cost_a, int cost_b);
void				ft_rorate_rr(t_stack **stack_a, t_stack **stack_b,
						int cost_a, int cost_b);
void				ft_rorate_rrr(t_stack **stack_a, t_stack **stack_b,
						int cost_a, int cost_b);
void				ft_simple_rotate(t_stack **stack_a, t_stack **stack_b,
						int cost_a, int cost_b);
void				ft_rotate_stack(t_stack **stack, int cost,
						void (*ft_rotate)(t_stack **),
						void (*ft_reverse_rotate)(t_stack **));
// next is ft_pa_all_stack_b

// need?
t_stack				*ft_find_target(t_stack **stack_a, t_stack *stack_b,
						int *flg);
t_stack				*ft_get_min_node(t_stack *stack_a);
t_stack				*ft_get_max_node(t_stack *stack_a);
t_stack				*ft_rotate_min(t_stack **stack_a, int min_idx, int size_a);
void				ft_select_rotate(t_stack **stack_a,
						t_stack *stack_a_target);
void				ft_rotate_ascending(t_stack **stack_a);
void				ft_assign_index_for_accending(t_stack **stack_a);

// free
void				ft_free_str(char **lst_str);
void				ft_free_stack(t_stack **stack_a);

// operations
void				ft_sa(t_stack **stack_a);
void				ft_ra(t_stack **stack_a);
void				ft_rra(t_stack **stack_a);
void				ft_rb(t_stack **stack_b);
void				ft_rrb(t_stack **stack_b);
void				ft_pa(t_stack **stack_a, t_stack **stack_b);
void				ft_pb(t_stack **stack_a, t_stack **stack_b);
// operations combo
void				ft_sa_ra(t_stack **stack_a);
void				ft_sa_rra(t_stack **stack_a);

// for debug
void				ft_print_stack(t_stack *stack);

#endif
