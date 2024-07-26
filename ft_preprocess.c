/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:37:50 by seungryk          #+#    #+#             */
/*   Updated: 2024/03/16 09:18:42 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h" 

void	delete_node(t_stack **head)
{
	t_stack	*prev;
	t_stack	*next;

	if (!(*head))
		return ;
	else if ((*head)->next == *head && (*head)->prev == *head)
	{
		free(*head);
		*head = NULL;
		return ;
	}
	else
	{
		prev = (*head)->prev;
		next = (*head)->next;
		prev->next = next;
		next->prev = prev;
		free(*head);
		*head = NULL;
		*head = next;
	}
}

void	add_index_l(t_ps *ps, int num)
{
	int		idx;
	t_stack	*head;
	t_stack	*node;

	idx = 1;
	head = ps->a_top;
	node = ps->a_top->prev;
	while (1)
	{
		if (num > head->num)
			idx++;
		head = head->next;
		if (head == ps->a_top)
			break ;
	}
	head->prev->idx = idx;
}

void	add_index_r(t_ps *ps)
{
	int		idx;
	t_stack	*curr;
	t_stack	*tail;

	curr = ps->a_top;
	while (1)
	{
		idx = 0;
		tail = ps->a_top->prev;
		while (tail != curr)
		{
			if (curr->num == tail->num)
				error_msg();
			else if (curr->num > tail->num)
				idx++;
			tail = tail->prev;
		}
		curr->idx += idx;
		curr = curr->next;
		if (curr == ps->a_top)
			break ;
	}
}
