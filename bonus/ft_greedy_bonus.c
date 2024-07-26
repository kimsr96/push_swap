/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_greedy_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:09:35 by seungryk          #+#    #+#             */
/*   Updated: 2024/03/14 15:05:38 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

static void	rotate_both(t_ps *ps, int *get_a, int *get_b)
{
	while (*get_a > 0 && *get_b > 0)
	{
		rr(ps);
		(*get_a)--;
		(*get_b)--;
	}
	while (*get_a < 0 && *get_b < 0)
	{
		rrr(ps);
		(*get_a)++;
		(*get_b)++;
	}
}

static int	check_min(int get_a, int get_b, int cnt_a, int cnt_b)
{
	if (cnt_a < 0)
		cnt_a *= -1;
	if (cnt_b < 0)
		cnt_b *= -1;
	if (get_a < 0)
		get_a *= -1;
	if (get_b < 0)
		get_b *= -1;
	if (cnt_a + cnt_b < get_a + get_b)
		return (1);
	else
		return (0);
}

static int	cnt_node_a(t_ps *ps, int n)
{
	int		cnt_a;
	int		size_a;
	t_stack	*node_a;

	cnt_a = 0;
	node_a = ps->a_top;
	size_a = ps->a_size;
	while (size_a)
	{
		if (n < node_a->idx && n < node_a->prev->idx && \
							node_a->idx < node_a->prev->idx)
			break ;
		if (n < node_a->idx && n > node_a->prev->idx && \
							node_a->idx > node_a->prev->idx)
			break ;
		cnt_a++;
		node_a = node_a->next;
		size_a--;
	}
	if (cnt_a > ps->a_size / 2)
		cnt_a = cnt_a - ps->a_size;
	return (cnt_a);
}

static void	find_node(t_ps *ps, int *get_a, int *get_b)
{
	int		cnt_a;
	int		cnt_b;
	int		idx;
	t_stack	*node_b;

	idx = 0;
	cnt_b = 0;
	node_b = ps->b_top;
	while (idx < ps->b_size)
	{
		cnt_a = cnt_node_a(ps, node_b->idx);
		if (idx > ps->b_size / 2)
			cnt_b = idx - ps->b_size;
		else
			cnt_b = idx;
		if (idx == 0 || check_min(*get_a, *get_b, cnt_a, cnt_b))
		{
			*get_a = cnt_a;
			*get_b = cnt_b;
		}
		node_b = node_b->next;
		idx++;
	}
}

void	greedy(t_ps *ps)
{
	int	get_a;
	int	get_b;

	while (ps->b_size)
	{
		get_a = 0;
		get_b = 0;
		find_node(ps, &get_a, &get_b);
		rotate_both(ps, &get_a, &get_b);
		rotate_a(ps, get_a);
		rotate_b(ps, get_b);
		pa(ps);
	}		
}
