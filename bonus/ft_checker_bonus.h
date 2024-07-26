/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:28:39 by seungryk          #+#    #+#             */
/*   Updated: 2024/03/18 15:39:39 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_BONUS_H
# define FT_CHECKER_BONUS_H

# include "../libft/libft.h"

typedef struct s_check
{
	char			*data;
	struct s_check	*next;
}t_check;

typedef struct s_stack
{
	int				num;
	int				idx;
	struct s_stack	*next;
	struct s_stack	*prev;
}t_stack;

typedef struct s_ps
{
	int			a_size;
	int			b_size;
	t_stack		*a_top;
	t_stack		*b_top;
	t_check		*cmd;
}t_ps;

/* ft_function_bonus.c */
void	swap(t_ps *ps, t_stack *head, char c);
void	rotate(t_ps *ps, char c, int flag);
void	r_rotate(t_ps *ps, char c, int flag);
void	pa(t_ps *ps);
void	pb(t_ps *ps);

/* ft_function2_bonus.c */
void	ss(t_ps *ps);
void	rr(t_ps *ps);
void	rrr(t_ps *ps);
void	rotate_a(t_ps *ps, int get_a);
void	rotate_b(t_ps *ps, int get_b);

/* ft_init_bonus.c */
t_stack	*new_node(int num, int idx);
t_stack	*add_node(t_stack **head, int num, int idx);
void	init_stack(t_ps *ps, char **argv);

/* ft_preprocess_bonus.c */
void	delete_node(t_stack **head);
void	add_index_l(t_ps *ps, int num);
void	add_index_r(t_ps *ps);

/* ft_utils_bonus.c */
int		is_sorted(t_stack *head);
void	*free_arr(char **str);

/* ft_small_stack_bonus.c */
void	sort_small_stack(t_ps *ps, int cnt, char c);

/* ft_sort_stack_bonus.c */
void	sort_stack(t_ps *ps);

/* ft_greedy_bonus.c */
void	greedy(t_ps *ps);

/* ft_error_bonus.c */
void	error_msg(void);
int		check_atoi(char *str);
void	check_num(int num, char *input);

/* ft_checker_bonus.c */
void	check_cmd(t_ps *ps);
#endif