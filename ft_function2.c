/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:46:51 by seungryk          #+#    #+#             */
/*   Updated: 2024/03/16 10:50:51 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

void	rr(t_ps *ps)
{
	rotate(ps, 'a', 0);
	rotate(ps, 'b', 0);
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_ps *ps)
{
	r_rotate(ps, 'a', 0);
	r_rotate(ps, 'b', 0);
	ft_putstr_fd("rrr\n", 1);
}

void	rotate_both(t_ps *ps, int *get_a, int *get_b)
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
