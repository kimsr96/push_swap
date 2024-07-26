/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:46:51 by seungryk          #+#    #+#             */
/*   Updated: 2024/03/16 10:54:26 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

void	ss(t_ps *ps)
{
	swap(ps, ps->a_top, 'a');
	swap(ps, ps->b_top, 'b');
}

void	rr(t_ps *ps)
{
	rotate(ps, 'a', 0);
	rotate(ps, 'b', 0);
}

void	rrr(t_ps *ps)
{
	r_rotate(ps, 'a', 0);
	r_rotate(ps, 'b', 0);
}

void	rotate_a(t_ps *ps, int get_a)
{
	while (get_a)
	{
		if (get_a > 0)
		{
			rotate(ps, 'a', 1);
			get_a--;
		}
		else
		{
			r_rotate(ps, 'a', 1);
			get_a++;
		}
	}
}

void	rotate_b(t_ps *ps, int get_b)
{
	while (get_b)
	{
		if (get_b > 0)
		{
			rotate(ps, 'b', 1);
			get_b--;
		}
		else
		{
			r_rotate(ps, 'b', 1);
			get_b++;
		}
	}
}
