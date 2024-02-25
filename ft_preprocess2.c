/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:37:50 by seungryk          #+#    #+#             */
/*   Updated: 2024/02/25 14:54:46 by seungryk         ###   ########.fr       */
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
	prev = (*head)->prev;
	next = (*head)->next;
	prev->next = next;
	next->prev = prev;
	free(*head);
	*head = next;
}

void	add_index(t_ps *ps)
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
			if (curr->num > tail->num)
				idx++;
			tail = tail->prev;
		}
		curr->idx += idx;
		curr = curr->prev;
		if (curr == ps->a_top->prev)
			break ;
	}
}
