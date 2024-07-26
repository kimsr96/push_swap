/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:00:39 by seungryk          #+#    #+#             */
/*   Updated: 2024/03/16 09:25:02 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

void	swap(t_ps *ps, t_stack *head, char c)
{
	t_stack	*temp;

	temp = head->next;
	head->prev->next = temp;
	temp->prev = head->prev;
	head->next = temp->next;
	temp->next->prev = head;
	temp->next = head;
	head->prev = temp;
	if (c == 'a')
		ps->a_top = temp;
	else
		ps->b_top = temp;
}

void	rotate(t_ps *ps, char c, int flag)
{
	t_stack	*head;

	if (c == 'a')
	{
		head = ps->a_top;
		if (head)
			ps->a_top = head->next;
		else
			return ;
		if (flag)
			ft_putstr_fd("ra\n", 1);
	}
	else
	{
		head = ps->b_top;
		if (head)
			ps->b_top = head->next;
		else
			return ;
		if (flag)
			ft_putstr_fd("rb\n", 1);
	}
}

void	r_rotate(t_ps *ps, char c, int flag)
{
	t_stack	*head;

	if (c == 'a')
	{
		head = ps->a_top;
		if (head)
			ps->a_top = head->prev;
		else
			return ;
		if (flag)
			ft_putstr_fd("rra\n", 1);
	}
	else
	{
		head = ps->b_top;
		if (head)
			ps->b_top = head->prev;
		else
			return ;
		if (flag)
			ft_putstr_fd("rrb\n", 1);
	}
}

void	pa(t_ps *ps)
{
	int		data;

	data = 0;
	if (ps->b_top)
	{
		data = ps->b_top->idx;
		delete_node(&(ps->b_top));
		ps->b_size--;
	}
	else
		return ;
	ps->a_top = add_node(&(ps->a_top), 0, data);
	ps->a_size++;
}

void	pb(t_ps *ps)
{
	int		data;

	data = 0;
	if (ps->a_top)
	{
		data = ps->a_top->idx;
		delete_node(&(ps->a_top));
		ps->a_size--;
	}
	else
		return ;
	ps->b_top = add_node(&(ps->b_top), 0, data);
	ps->b_size++;
}
