/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_stack_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:55:30 by seungryk          #+#    #+#             */
/*   Updated: 2024/03/16 10:35:46 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

static void	sort_2_stack(t_ps *ps)
{
	swap(ps, ps->a_top, 'a');
}

static void	sort_3_stack(t_ps *ps, char c)
{
	int	arr[3];

	arr[0] = ps->a_top->idx;
	arr[1] = ps->a_top->next->idx;
	arr[2] = ps->a_top->prev->idx;
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] < arr[2])
		swap(ps, ps->a_top, c);
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] > arr[2])
		rotate(ps, c, 1);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] > arr[2])
		r_rotate(ps, c, 1);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] < arr[2])
	{
		swap(ps, ps->a_top, c);
		rotate(ps, c, 1);
	}
	else if (arr[0] > arr[1] && arr[1] > arr[2] && arr[0] > arr[2])
	{
		swap(ps, ps->a_top, c);
		r_rotate(ps, c, 1);
	}
	else
		return ;
}

void	sort_small_stack(t_ps *ps, int cnt, char c)
{
	if (cnt == 2)
		sort_2_stack(ps);
	else if (cnt == 3)
		sort_3_stack(ps, c);
	else
		return ;
}
