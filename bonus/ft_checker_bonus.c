/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:03:26 by seungryk          #+#    #+#             */
/*   Updated: 2024/03/16 09:36:19 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

void	free_list(t_check **head)
{
	t_check	*curr;
	t_check	*temp;

	curr = *head;
	while (curr)
	{
		temp = curr->next;
		free(curr->data);
		free(curr);
		curr = temp;
	}
	*head = NULL;
}

void	find_cmd(t_ps *ps, t_check *lst, size_t len)
{
	if (!ft_strncmp(lst->data, "sa\n", len))
		swap(ps, ps->a_top, 'a');
	else if (!ft_strncmp(lst->data, "sb\n", len))
		swap(ps, ps->b_top, 'b');
	else if (!ft_strncmp(lst->data, "ss\n", len))
		ss(ps);
	else if (!ft_strncmp(lst->data, "pa\n", len))
		pa(ps);
	else if (!ft_strncmp(lst->data, "pb\n", len))
		pb(ps);
	else if (!ft_strncmp(lst->data, "ra\n", len))
		rotate(ps, 'a', 0);
	else if (!ft_strncmp(lst->data, "rb\n", len))
		rotate(ps, 'b', 0);
	else if (!ft_strncmp(lst->data, "rr\n", len))
		rr(ps);
	else if (!ft_strncmp(lst->data, "rra\n", len))
		r_rotate(ps, 'a', 0);
	else if (!ft_strncmp(lst->data, "rrb\n", len))
		r_rotate(ps, 'b', 0);
	else if (!ft_strncmp(lst->data, "rrr\n", len))
		rrr(ps);
	else
		error_msg();
}

void	run_cmd(t_ps *ps, t_check **head)
{
	size_t	len;
	t_check	*curr;

	curr = *head;
	while (curr)
	{
		len = ft_strlen(curr->data);
		find_cmd(ps, curr, len);
		curr = curr->next;
	}
}

void	append_node(t_check **head, char *data)
{
	t_check	*curr;
	t_check	*new;

	new = (t_check *)malloc(sizeof(t_check));
	new->data = data;
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		curr = *head;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}

void	check_cmd(t_ps *ps)
{
	char	*line;
	t_check	*head;

	head = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		append_node(&head, line);
	}
	run_cmd(ps, &head);
	if (is_sorted(ps->a_top))
		ft_putstr_fd("OK\n", 2);
	else
		ft_putstr_fd("KO\n", 2);
	free_list(&head);
}
