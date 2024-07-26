/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:52:42 by seungryk          #+#    #+#             */
/*   Updated: 2024/03/17 08:29:19 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

static void	last_sort(t_ps *ps)
{
	int		cnt;
	t_stack	*node;

	node = ps->a_top;
	cnt = 0;
	while (cnt < ps->a_size)
	{
		if (node->idx == 1)
			break ;
		cnt++;
		node = node->next;
	}
	node = ps->a_top;
	while (node->idx > node->prev->idx)
	{
		if (cnt < ps->a_size / 2)
			rotate(ps, 'a', 1);
		else
			r_rotate(ps, 'a', 1);
		node = ps->a_top;
	}
}

static void	a_to_b(t_ps *ps, int pivot, int p1, int p2)
{
	int	size;

	size = ps->a_size;
	if (size <= 3)
	{
		sort_small_stack(ps, size, 'a');
		return ;
	}
	while (size > 3)
	{
		if (ps->a_top->idx > p2)
			rotate(ps, 'a', 1);
		else
		{
			pb(ps);
			if (ps->b_top->idx < p1)
				rotate(ps, 'b', 1);
		}
		size--;
	}
	a_to_b(ps, pivot, p2 + ((pivot - p2) / 3), p2 + (2 * (pivot - p2) / 3));
}

static void	free_node(t_ps *ps)
{
	t_stack	*curr;
	t_stack	*temp;

	curr = ps->a_top;
	while (curr->next != ps->a_top)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	free(curr);
}

void	sort_stack(t_ps *ps)
{
	if (is_sorted(ps->a_top))
		exit (0);
	a_to_b(ps, ps->a_size, ps->a_size / 3, 2 * (ps->a_size / 3));
	greedy(ps);
	last_sort(ps);
	free_node(ps);
}
