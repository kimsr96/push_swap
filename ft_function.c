/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:00:39 by seungryk          #+#    #+#             */
/*   Updated: 2024/02/23 16:39:16 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
	{
		ps->a_top = temp;
		ft_putstr_fd("sa\n", 1);
	}
	else
	{
		ps->b_top = temp;
		ft_putstr_fd("sb\n", 1);
	}
}

void	rotate(t_ps *ps, char c)
{
	t_stack	*head;

	if (c == 'a')
	{
		head = ps->a_top;
		if (head)
			ps->a_top = head->next;
		else
			return ;
		ft_putstr_fd("ra\n", 1);
	}
	else
	{
		head = ps->b_top;
		if (head)
			ps->b_top = head->next;
		else
			return ;
		ft_putstr_fd("rb\n", 1);
	}
}

void	r_rotate(t_ps *ps, char c)
{
	t_stack	*head;

	if (c == 'a')
	{
		head = ps->a_top;
		if (head)
			ps->a_top = head->prev;
		else
			return ;
		ft_putstr_fd("rra\n", 1);
	}
	else
	{
		head = ps->b_top;
		if (head)
			ps->b_top = head->prev;
		else
			return ;
		ft_putstr_fd("rrb\n", 1);
	}
}

void	pa(t_ps *ps)
{
	int		data;
	t_stack	*node;

	data = 0;
	if (ps->b_top)
	{
		data = ps->b_top->num;
		delete_node(&(ps->b_top));
		ps->b_size--;
	}
	else
		return ;
	node = new_node(data);
	ps->a_top = add_node(&(ps->a_top), data);
	ps->a_size++;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_ps *ps)
{
	int		data;
	t_stack	*node;

	data = 0;
	if (ps->a_top)
	{
		data = ps->a_top->num;
		delete_node(&(ps->a_top));
		ps->a_size--;
	}
	else
		return ;
	node = new_node(data);
	ps->b_top = add_node(&(ps->b_top), data);
	ps->b_size++;
	ft_putstr_fd("pb\n", 1);
}
