/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:04:06 by seungryk          #+#    #+#             */
/*   Updated: 2024/02/25 12:30:09 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include <stdio.h>
#include "./libft/libft.h"

typedef struct s_stack
{
	int             num;
	int             idx;
	struct s_stack  *next;
	struct s_stack  *prev;
}t_stack;

typedef struct s_ps
{
    int     arr[3];
    int     a_size;
    int     b_size;
	t_stack *a_top;
	t_stack *b_top;
}t_ps;

/* ft_function.c */
void	swap(t_ps *ps, t_stack *head, char c);
void	rotate(t_ps *ps, char c);
void	r_rotate(t_ps *ps, char c);
//void	push(t_ps *ps, char c);
void    pa(t_ps *ps);
void    pb(t_ps *ps);

/* ft_preprocess2.c */
void	add_index(t_ps *ps);
void	delete_node(t_stack **head);

/* ft_preprocess.c */
t_stack	*new_node(int data);
t_stack *add_node(t_stack **head, int data);
void	init_stack(t_ps *ps, char **argv);

/* ft_utils.c */
int     ft_min(int num1, int num2, int num3);
int     ft_max(int num1, int num2, int num3);
int		is_sorted(t_stack *head);
void    print_stack(t_stack *head, char c);

/* ft_small_stack.c */
void	sort_small_stack(t_ps *ps, int cnt, char c);
//void    sort_2_stack(t_ps *ps);

/* ft_sort_stack.c */
void    sort_stack(t_ps *ps);

#endif