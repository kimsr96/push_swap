/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:55:30 by seungryk          #+#    #+#             */
/*   Updated: 2024/02/25 12:32:44 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_2_stack(t_ps *ps, char c)
{
	if (c == 'a')
		swap(ps, ps->a_top, 'a');
	else
		swap(ps, ps->b_top, 'b');
}

void	get_num(t_ps *ps, char c)
{
	if (c == 'a')
	{
		ps->arr[0] = ps->a_top->num;
		ps->arr[1] = ps->a_top->next->num;
		ps->arr[2] = ps->a_top->prev->num;
	}
	else
	{
		ps->arr[0] = ps->b_top->num;
		ps->arr[1] = ps->b_top->next->num;
		ps->arr[2] = ps->b_top->prev->num;
	}
}

void	sort_3_stack(t_ps *ps, char c)
{
	int	arr[3];

	get_num(ps, c);
	arr[0] = ps->arr[0];
	arr[1] = ps->arr[1];
	arr[2] = ps->arr[2];
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] < arr[2])
		swap(ps, ps->a_top, c);
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] > arr[2])
		rotate(ps, c);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] > arr[2])
		r_rotate(ps, c);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] < arr[2])
	{
		swap(ps, ps->a_top, c);
		rotate(ps, c);
	}
	else if (arr[0] > arr[1] && arr[1] > arr[2] && arr[0] > arr[2])
	{
		swap(ps, ps->a_top, c);
		r_rotate(ps, c);
	}
	else
		return ;
}

//void	sort_4_stack(t_ps *ps, char c)
//{
//	int		num;
//	t_stack	*curr;

//	num = ps->a_top->num;
//	curr = ps->a_top->next;
//	while (curr != ps->a_top)
//	{
//		if (num > curr->num)
//			num = curr->num;
//		curr = curr->next;
//	}
//	if (curr->prev->num == num)
//		r_rotate(ps, 'a');
//	else
//	{
//		while (curr->num != num)
//		{
//			rotate(ps, 'a');
//			curr = curr->next;
//		}
//	}
//	pb(ps);
//	sort_3_stack(ps);
//	pa(ps);
//}

//void	sort_5_stack(t_ps *ps, char c)
//{
//	int		num;
//	t_stack	*curr;

//	num = ps->a_top->num;
//	curr = ps->a_top->next;
//	while (curr != ps->a_top)
//	{
//		if (num > curr->num)
//			num = curr->num;
//		curr = curr->next;
//	}
//	if (curr->prev->num == num)
//		r_rotate(ps, 'a');
//	else
//	{
//		while (curr->num != num)
//		{
//			rotate(ps, 'a');
//			curr = curr->next;
//		}
//	}
//	pb(ps);
//	sort_4_stack(ps);
//	pa(ps);
//}

void	sort_small_stack(t_ps *ps, int cnt, char c)
{
	if (cnt == 2)
		sort_2_stack(ps, c);
	else if (cnt == 3)
		sort_3_stack(ps, c);
	//else if (cnt == 4)
	//	sort_4_stack(ps, c);
	//else if (cnt == 5)
	//	sort_5_stack(ps, c);
	else
		return ;
}