/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:52:42 by seungryk          #+#    #+#             */
/*   Updated: 2024/02/25 19:18:57 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	q_sort(t_ps *ps, int p1, int p2)
{
	int	num;
	int	cnt;
	int	rrb;

	rrb = 0;
	cnt = ps->a_size;
	while (cnt > 3)
	{
		num = ps->a_top->num;
		if (num >= p2)
			rotate(ps, 'a');
		else
		{
			pb(ps);
			if (num >= p1)
			{
				rotate(ps, 'b');
				rrb++;
			}
		}
		cnt--;
	}
	while (rrb)
	{
		r_rotate(ps, 'b');
		rrb--;
	}
}

void	sort_a(t_ps *ps, int p1, int p2)
{
	int size;

	size = ps->a_size;
	if (size <= 3)
	{
		sort_small_stack(ps, ps->a_size, 'a');
		return ;
	}
	q_sort(ps, p1, p2);
	sort_a(ps, p2 + (p1 / 2), p2 + 2 * (p2 / 2));
	//sort_b(ps, size, p2 + (p1 / 2), p2 + 2 * (p2 / 2));
	//sort_b(ps);
}

void    find_node(t_ps *ps)
{
	int	cnt;
	int	min;
	t_stack	*a_top;
	t_stack	*b_top;

	cnt = ps->b_size;
	while (cnt)
	{
		a_top = ps->a_top;
		b_top = ps->b_top;
		
		cnt--;
	}
}

void    greedy(t_ps *ps)
{
	while (ps->b_size)
	{
		find_node();
	}
}

void    sort_stack(t_ps *ps)
{
	sort_a(ps, ps->a_size / 4, ps->a_size / 2);
	//print_stack(ps->a_top, 'a');
	//print_stack(psq->b_top, 'b');
}
//void	sort_stack(t_ps *ps)
//{
//	int	chunk;
//	int	n;
//	int	flag;

//	chunk = 10;
//	n = 1;
//	flag = 1;
//	while (ps->a_size)
//	{
//		if (ps->a_top->num <= n)
//		{
//			pb(ps);
//			n++;
//		}
//		else if (ps->a_top->num <= n + chunk)
//		{
//			pb(ps);
//			rotate(ps, 'b');
//			n++;
//		}
//		else
//		{
//			if (n < ps->a_size)
//				rotate(ps, 'a');
//			else
//				r_rotate(ps, 'a');
//		}
//	}
//	//printf("n: %d", n);
//	while (ps->b_size)
//	{
//		if (ps->b_top->num == n - 1)
//		{
//			pa(ps);
//			n--;
//			flag = 1;
//		}
//		else if (ps->b_top->prev->num == n - 1)
//		{
//			r_rotate(ps, 'b');
//			pa(ps);
//			n--;
//			flag = 0;
//		}
//		else
//		{
//			if (flag)
//				rotate(ps, 'b');
//			else
//				r_rotate(ps, 'b');
//		}
//	}
//}
